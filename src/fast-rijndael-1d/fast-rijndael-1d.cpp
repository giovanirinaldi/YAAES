#include "fast-rijndael-1d.h"
#include <cstring>
#include <cstdio>
#include <ctime>

#define DEBUG 0
#define STDOUT stdout

FastRijndael::FastRijndael(KeySize ks, BlockSize bs, Mode mode){
	_exp_key = NULL;
	_round = 0;
	_key_size = ks;
	_block_size = bs;	//bits
	_block_char_size = bs/8;
	_nb = bs/32;
	_nk = ks/32;
	_mode = mode;
	if (_mode != ECB){
	/*	srand(time(NULL));	
		_iv = new unsigned char* [4];
		for (int i = 0; i < 4; i++){
			_iv[i] = new unsigned char [4];
		}
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				_iv[i][j] = rand()%256;
			}
		}*/
		generateIV();
	}
	else{
		_iv = NULL;
	}
	switch (_nk){
		case 4:	_nr = 10;	break;
		case 6:	_nr = 12;	break;
		case 8:	_nr = 14;	break;
	}
	_nek = _nb * (_nr + 1);	// # of byte columns of expanded key
	_initd = false;
}

FastRijndael::~FastRijndael(){
	if (_exp_key){
/*		for (int i = 0; i < _nek; i++){
			delete[] _exp_key[i];	
		}*/
/*		delete[] _exp_key;
		_exp_key = NULL;*/
	}
	if (_mode != ECB){
/*		for (int i = 0; i < 4; i++){
			delete[] _iv[i];
		}	*/
/*		delete[] _iv;
		_iv = NULL;*/
	}
}

void FastRijndael::cleanUp(){
	if (_initd)
		delete[] _exp_key;
	if (_mode != ECB)
		delete[] _iv;
}

void FastRijndael::generateIV(){	
	srand(time(NULL));	
	_iv = new unsigned char [_nb*4];
/*	for (int i = 0; i < 4; i++){
		_iv[i] = new unsigned char [4];
	}*/
//	printf("iv: ");
	for (int i = 0; i < _nb*4; i++){
//		for (int j = 0; j < 4; j++){
		_iv[i] = rand()%256;
	//		printf("%x ", _iv[i][j]);
//		}
	}	
//	printf("\n");
}

void FastRijndael::getIV(unsigned char* iv){
//	for (int i = 0; i < 4; i++){
		memcpy(&iv[0], &_iv[0], _nb*4);
//	}
}

void FastRijndael::setIV(unsigned char* iv){
//	for (int i = 0; i < 4; i++){
	memcpy(&_iv[0], &iv[0], _nb*4);
//	}
}

void FastRijndael::makeKey(unsigned char* key){
	if (key == NULL){
		return;
	}

	_exp_key = new unsigned char [_nek*4];	
/*	for (int i = 0; i < _nek; i++){
		_exp_key[i] = new unsigned char [4];
	}*/
//	for (int i = 0; i < _nk; i++){
	memcpy(&_exp_key[0], &key[0], _nk*4);
/*	for (int i = 0; i < _nk*4; i+=4){
		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i], _exp_key[i+1], _exp_key[i+2], _exp_key[i+3]);
	}*/
//	}
/*	for (int i = _nk; i < _nek; i++){
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		memcpy(&_exp_key[i*4], &_exp_key[(i-1)*4], 4);
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		if (_nk == 8){			// 256 bit key	- one subword only
			if ((i-4)%8 == 0){	// between each full step (fullstep -> rot,sub,rcon,xor)
				subWord(&_exp_key[i*4]);
			}
		}
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		if (i % _nk == 0){
			rotWord(&_exp_key[i*4]);
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
			subWord(&_exp_key[i*4]);
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
			_exp_key[i*4] ^= _rcon[i/_nk];	//xor Rcon
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		}
		for (int j = 0; j < 4; j++){
			_exp_key[i*4+j] ^= _exp_key[(i-_nk)*4+j];
		}
		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
	}*/
	register int imult4;
	for (int i = _nk; i < _nek; i++){
		imult4 = i*4;
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		memcpy(&_exp_key[imult4], &_exp_key[(i-1)*4], 4);
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		if (_nk == 8){			// 256 bit key	- one subword only
			if ((i-4)%8 == 0){	// between each full step (fullstep -> rot,sub,rcon,xor)
				subWord(&_exp_key[imult4]);
			}
		}
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		if (i % _nk == 0){
			rotWord(&_exp_key[imult4]);
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
			subWord(&_exp_key[imult4]);
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
			_exp_key[imult4] ^= _rcon[i/_nk];	//xor Rcon
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		}
		for (int j = 0; j < 4; j++){
			_exp_key[imult4+j] ^= _exp_key[(i-_nk)*4+j];
		}
		//printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
	}
	_initd = true;
}
		
void FastRijndael::rotWord(unsigned char* column){
	unsigned char temp = column[0];
	memcpy(&column[0], &column[1], 1);
	memcpy(&column[1], &column[2], 1);
	memcpy(&column[2], &column[3], 1);
	column[3] = temp;
//	column[0] = column[1];
//	column[1] = column[2];
//	column[2] = column[3];
//	column[3] = temp;
}

void FastRijndael::subWord(unsigned char* column){
	column[0] = _sbox[column[0]];
	column[1] = _sbox[column[1]];
	column[2] = _sbox[column[2]];
	column[3] = _sbox[column[3]];
//	for (int i = 0; i < 4; i++){
//		column[i] = _sbox[column[i]];
//	}
}

void FastRijndael::subBytes(unsigned char* block){
	for (int i = 0; i < 16; i++){	// nb*4
	//	for (int j = 0; j < 4; j++){
			block[i] = _sbox[block[i]];
	//	}
	}
}

void FastRijndael::subBytesMainDiagonal(unsigned char* block){
/*	for (int i = 0; i < 4; i++){
		block[i][i] = _sbox[block[i][i]];
	}*/
	block[0] = _sbox[block[0]];
	block[5] = _sbox[block[5]];
	block[10] = _sbox[block[10]];
	block[15] = _sbox[block[15]];
}

void FastRijndael::invSubBytes(unsigned char* block){
	for (int i = 0; i < 16; i++){	// nb*4
//		for (int j = 0; j < 4; j++){
			block[i] = _inv_sbox[block[i]];
//		}
	}
}

void FastRijndael::shiftRows(unsigned char* block){
/*	unsigned char* temp = new unsigned char [4];
	register int imult4;
	for (int i = 1; i < 4; i++){ //1to_nb	//row 0 do not shift
		imult4 = i*4;
		memcpy(temp, &block[imult4], 4);
		memcpy(&block[imult4], temp+i, 4-i);
		memcpy(&block[imult4]+(4-i), temp, i);
	}
	delete[] temp;*/
	register unsigned char temp = block[5];
	block[5] = block[9]; block[9] = block[13]; block[13] = block[1]; block[1] = temp;
	temp = block[6]; register unsigned char temp1 = block[2];
	block[2] = block[10]; block[6] = block[14]; block[10] = temp1; block[14] = temp;
	temp = block[3];
	block[3] = block[15]; block[15] = block[11]; block[11] = block[7]; block[7] = temp;
}

//void FastRijndael::shiftRowsMainDiagonal(unsigned char** block){
//	block[1][0] = block[1][1];
//	block[2][0] = block[2][2];
//	block[3][0] = block[3][3];
//}

void FastRijndael::invShiftRows(unsigned char* block){
/*	unsigned char* temp = new unsigned char [4];
	register int imult4;
	for (int i = 1; i < 4; i++){	//row 0 do not shift
		imult4 = i*4;
		memcpy(temp, &block[imult4], 4);
		memcpy(&block[imult4], temp+(4-i), i);
		memcpy(&block[imult4]+i, temp, 4-i);
	}
	delete[] temp;*/
	register unsigned char temp = block[5];
	block[5] = block[1]; block[1] = block[13]; block[13] = block[9]; block[9] = temp;
	temp = block[10]; register unsigned char temp1 = block[14];
	block[10] = block[2]; block[14] = block[6]; block[2] = temp; block[6] = temp1;
	temp = block[15];
	block[15] = block[3]; block[3] = block[7]; block[7] = block[11]; block[11] = temp;
}

void FastRijndael::mixColumns(unsigned char* block){
//	unsigned char* temp = new unsigned char [4];	//utilizado para guardar coluna atual
//	for (int j = 0; j < 4; j++){
//		memcpy(temp, &block[0][j], 1);
//		memcpy(temp+1, &block[1][j], 1);
//		memcpy(temp+2, &block[2][j], 1);
//		memcpy(temp+3, &block[3][j], 1);
//		for (int i = 0; i < 4; i++){
//			block[i][j] = 0x00;
//			for (int m = 0; m < 4; m ++){
///*				if (_mix[i][m] >= 2){
//					block[i][j] ^= temp[m] << 1;
//					if (_mix[i][m] == 3){
//						block[i][j] ^= temp[m];
//					}
//					if (temp[m] & 0x80){	// antes, primeiro bit mais signficativo era 1
//						block[i][j] ^= 0x1b;
//					}	
//				}		
//				else{
//					block[i][j] ^= temp[m];
//				}*/
//				block[i][j] ^= mult(temp[m], _mix[i][m]);
//			}
//		}
//	}
//	delete[] temp;

	//mult comes from _mix values (2,3,1,1......3,1,1,2);
	unsigned char* temp = new unsigned char [16];
	memcpy(temp, block, 16);
	/*block[0] = mult_table[temp[0]][2] ^ mult_table[temp[1]][3] ^ temp[2] ^ temp[3];
	block[1] = temp[0] ^ mult_table[temp[1]][2] ^ mult_table[temp[2]][3] ^ temp[3];
	block[2] = temp[0] ^ temp[1] ^ mult_table[temp[2]][2] ^ mult_table[temp[3]][3];
	block[3] = mult_table[temp[0]][3] ^ temp[1] ^ temp[2] ^ mult_table[temp[3]][2];
	
	block[4] = mult_table[temp[4]][2] ^ mult_table[temp[5]][3] ^ temp[6] ^ temp[7];
	block[5] = temp[4] ^ mult_table[temp[5]][2] ^ mult_table[temp[6]][3] ^ temp[7];
	block[6] = temp[4] ^ temp[5] ^ mult_table[temp[6]][2] ^ mult_table[temp[7]][3];
	block[7] = mult_table[temp[4]][3] ^ temp[5] ^ temp[6] ^ mult_table[temp[7]][2];
	
	block[8] = mult_table[temp[8]][2] ^ mult_table[temp[9]][3] ^ temp[10] ^ temp[11];
	block[9] = temp[8] ^ mult_table[temp[9]][2] ^ mult_table[temp[10]][3] ^ temp[11];
	block[10] = temp[8] ^ temp[9] ^ mult_table[temp[10]][2] ^ mult_table[temp[11]][3];
	block[11] = mult_table[temp[8]][3] ^ temp[9] ^ temp[10] ^ mult_table[temp[11]][2];

	block[12] = mult_table[temp[12]][2] ^ mult_table[temp[13]][3] ^ temp[14] ^ temp[15];
	block[13] = temp[12] ^ mult_table[temp[13]][2] ^ mult_table[temp[14]][3] ^ temp[15];
	block[14] = temp[12] ^ temp[13] ^ mult_table[temp[14]][2] ^ mult_table[temp[15]][3];
	block[15] = mult_table[temp[12]][3] ^ temp[13] ^ temp[14] ^ mult_table[temp[15]][2];*/
	
	block[0] = mult_2_table[temp[0]] ^ mult_3_table[temp[1]] ^ temp[2] ^ temp[3];
	block[1] = temp[0] ^ mult_2_table[temp[1]] ^ mult_3_table[temp[2]] ^ temp[3];
	block[2] = temp[0] ^ temp[1] ^ mult_2_table[temp[2]] ^ mult_3_table[temp[3]];
	block[3] = mult_3_table[temp[0]] ^ temp[1] ^ temp[2] ^ mult_2_table[temp[3]];

	block[4] = mult_2_table[temp[4]] ^ mult_3_table[temp[5]] ^ temp[6] ^ temp[7];
	block[5] = temp[4] ^ mult_2_table[temp[5]] ^ mult_3_table[temp[6]] ^ temp[7];
	block[6] = temp[4] ^ temp[5] ^ mult_2_table[temp[6]] ^ mult_3_table[temp[7]];
	block[7] = mult_3_table[temp[4]] ^ temp[5] ^ temp[6] ^ mult_2_table[temp[7]];

	block[8] = mult_2_table[temp[8]] ^ mult_3_table[temp[9]] ^ temp[10] ^ temp[11];
	block[9] = temp[8] ^ mult_2_table[temp[9]] ^ mult_3_table[temp[10]] ^ temp[11];
	block[10] = temp[8] ^ temp[9] ^ mult_2_table[temp[10]] ^ mult_3_table[temp[11]];
	block[11] = mult_3_table[temp[8]] ^ temp[9] ^ temp[10] ^ mult_2_table[temp[11]];

	block[12] = mult_2_table[temp[12]] ^ mult_3_table[temp[13]] ^ temp[14] ^ temp[15];
	block[13] = temp[12] ^ mult_2_table[temp[13]] ^ mult_3_table[temp[14]] ^ temp[15];
	block[14] = temp[12] ^ temp[13] ^ mult_2_table[temp[14]] ^ mult_3_table[temp[15]];
	block[15] = mult_3_table[temp[12]] ^ temp[13] ^ temp[14] ^ mult_2_table[temp[15]];

	delete[] temp;
}

void FastRijndael::mixOneColumn(unsigned char* block, int column){
/*	unsigned char* temp = new unsigned char [4];	//utilizado para guardar coluna atual
	memcpy(temp, &block[0][column], 1);
	memcpy(temp+1, &block[1][column], 1);
	memcpy(temp+2, &block[2][column], 1);
	memcpy(temp+3, &block[3][column], 1);
	for (int i = 0; i < 4; i++){*/
/*	tempMixc0 = block[0][column];
	tempMixc1 = block[1][column];
	tempMixc2 = block[2][column];
	tempMixc3 = block[3][column];

	block[0][column] = mult(tempMixc0,0x02) ^ mult(tempMixc1,0x03) ^ tempMixc2 ^ tempMixc3;
	block[1][column] = tempMixc0 ^ mult(tempMixc1,0x02) ^ mult(tempMixc2,0x3) ^ tempMixc3;
	block[2][column] = tempMixc0 ^ tempMixc1 ^ mult(tempMixc2,0x02) ^ mult(tempMixc3,0x03);
	block[3][column] = mult(tempMixc0,0x03) ^ tempMixc1 ^ tempMixc2 ^ mult(tempMixc3,0x02);*/

	register int l0,l1,l2,l3;
	l0 = column*4; l1 = l0 + 1; l2 = l0 + 2; l3 = l0 + 3;

	unsigned char* temp = new unsigned char [4];
	memcpy(temp, &block[l0], 4);

	block[l0] = mult_2_table[temp[0]] ^ mult_3_table[temp[1]] ^ temp[2] ^ temp[3];
	block[l1] = temp[0] ^ mult_2_table[temp[1]] ^ mult_3_table[temp[2]] ^ temp[3];
	block[l2] = temp[0] ^ temp[1] ^ mult_2_table[temp[2]] ^ mult_3_table[temp[3]];
	block[l3] = mult_3_table[temp[0]] ^ temp[1] ^ temp[2] ^ mult_2_table[temp[3]];

	delete[] temp;
	
/*		block[i][column] = 0x00;
		for (int m = 0; m < 4; m ++){*/
/*			if (_mix[i][m] >= 2){
				block[i][column] ^= temp[m] << 1;
				if (_mix[i][m] == 3){
					block[i][column] ^= temp[m];
				}
				if (temp[m] & 0x80){	// antes, primeiro bit mais signficativo era 1
					block[i][column] ^= 0x1b;
				}	
			}		
			else{
				block[i][column] ^= temp[m];
			}*/
/*			block[i][column] ^= mult(temp[m], _mix[i][m]);
		}
	}
	delete[] temp;*/
}

//unsigned char FastRijndael::mult(unsigned char a, unsigned char b) {
//	return mult_table[a][b];
//}

//unsigned char FastRijndael::div(unsigned char a, unsigned char b) {
//	return div_table[a][b];
//}

void FastRijndael::invMixColumns(unsigned char* block){
//	unsigned char* temp = new unsigned char [4];	//utilizado para guardar coluna atual
//	for (int j = 0; j < 4; j++){
//		memcpy(temp, &block[0][j], 1);
//		memcpy(temp+1, &block[1][j], 1);
//		memcpy(temp+2, &block[2][j], 1);
//		memcpy(temp+3, &block[3][j], 1);
//		for (int i = 0; i < 4; i++){
//			block[i][j] = 0x00;
//			for (int m = 0; m < 4; m ++){
//					block[i][j] ^= mult(temp[m], _inv_mix[i][m]);
//			}
//		}
//	}
//	delete[] temp;
	
	//mult comes from _inv_mix values (2,3,1,1......3,1,1,2);
	unsigned char* temp = new unsigned char [16];
	memcpy(temp, block, 16);
	block[0] = mult_14_table[temp[0]] ^ mult_11_table[temp[1]] ^ mult_13_table[temp[2]] ^ mult_9_table[temp[3]];
	block[1] = mult_9_table[temp[0]] ^ mult_14_table[temp[1]] ^ mult_11_table[temp[2]] ^ mult_13_table[temp[3]];
	block[2] = mult_13_table[temp[0]] ^ mult_9_table[temp[1]] ^ mult_14_table[temp[2]] ^ mult_11_table[temp[3]];
	block[3] = mult_11_table[temp[0]] ^ mult_13_table[temp[1]] ^ mult_9_table[temp[2]] ^ mult_14_table[temp[3]];

	block[4] = mult_14_table[temp[4]] ^ mult_11_table[temp[5]] ^ mult_13_table[temp[6]] ^ mult_9_table[temp[7]];
	block[5] = mult_9_table[temp[4]] ^ mult_14_table[temp[5]] ^ mult_11_table[temp[6]] ^ mult_13_table[temp[7]];
	block[6] = mult_13_table[temp[4]] ^ mult_9_table[temp[5]] ^ mult_14_table[temp[6]] ^ mult_11_table[temp[7]];
	block[7] = mult_11_table[temp[4]] ^ mult_13_table[temp[5]] ^ mult_9_table[temp[6]] ^ mult_14_table[temp[7]];

	block[8] = mult_14_table[temp[8]] ^ mult_11_table[temp[9]] ^ mult_13_table[temp[10]] ^ mult_9_table[temp[11]];
	block[9] = mult_9_table[temp[8]] ^ mult_14_table[temp[9]] ^ mult_11_table[temp[10]] ^ mult_13_table[temp[11]];
	block[10] = mult_13_table[temp[8]] ^ mult_9_table[temp[9]] ^ mult_14_table[temp[10]] ^ mult_11_table[temp[11]];
	block[11] = mult_11_table[temp[8]] ^ mult_13_table[temp[9]] ^ mult_9_table[temp[10]] ^ mult_14_table[temp[11]];

	block[12] = mult_14_table[temp[12]] ^ mult_11_table[temp[13]] ^ mult_13_table[temp[14]] ^ mult_9_table[temp[15]];
	block[13] = mult_9_table[temp[12]] ^ mult_14_table[temp[13]] ^ mult_11_table[temp[14]] ^ mult_13_table[temp[15]];
	block[14] = mult_13_table[temp[12]] ^ mult_9_table[temp[13]] ^ mult_14_table[temp[14]] ^ mult_11_table[temp[15]];
	block[15] = mult_11_table[temp[12]] ^ mult_13_table[temp[13]] ^ mult_9_table[temp[14]] ^ mult_14_table[temp[15]];

	delete[] temp;
}

void FastRijndael::addRoundKey(unsigned char* block){
//	for (int i = 0; i < 4; i++){
//		for (int j = 0; j < 4; j++){
//			block[i][j] ^= _exp_key[j+_round*4][i];	//this is why the inverse matrix of key actually works with the (not-inversed) block text
//		}
//	}
	register int round_key = _round*16;
	for (int i = 0; i < 16; i++){
		block[i] ^= _exp_key[round_key+i];
	}
}

void FastRijndael::addRoundKeySwappedMCRoundTwo(unsigned char* block){
//	unsigned char** temp_exp_key = new unsigned char*[4];
//	for (int i = 0; i < 4; i++){
//		temp_exp_key[i] = new unsigned char[4];
//	}
//	for (int i = 0; i < 4; i++){
//		for (int j = 0; j < 4; j++){
//			temp_exp_key[i][j] = _exp_key[j+2*4][i];
//		}
//	}
//	invMixColumns(temp_exp_key);
//#if DEBUG
//	printf("k2 with invMixColumns (for swapping, at round 2, of MC with last ARK)\n");
//#endif
//	for (int i = 0; i < 4; i++){
//		for (int j = 0; j < 4; j++){
//			block[i][j] ^= temp_exp_key[i][j];	//this is why the inverse matrix of key actually works with the (not-inversed) block text
//#if DEBUG
//			printf("%.2x ", temp_exp_key[i][j]);
//#endif
//		}
//#if DEBUG
//		printf("\n");
//#endif
//	}
	unsigned char* temp_exp_key = new unsigned char [16];
	memcpy(temp_exp_key, &_exp_key[32], 16);	//32 = 16 round key 0 + 16 round key 1; then round key 2
	invMixColumns(temp_exp_key);
	for (int i = 0; i < 16; i++){
		block[i] ^= temp_exp_key[i];
	}
	delete[] temp_exp_key;
}

void FastRijndael::xorBlock(unsigned char* a, unsigned char* b){
	for (int i = 0; i < 16; i++){
//		for (int j = 0; j < 4; j++){
		a[i] ^= b[i];
//		}
	}
}

//params: total blocks, block data pointer (with allocated pad size) and length)
//returns: new length of data block padded.
void FastRijndael::makePadding(unsigned char* block, int &length, int blocks){
	char pad = blocks*128/8 - length;
	int i;
	for (i = length; i < (blocks)*128/8; i++){
		block[i] = pad;
	}
	length = i;
}

void FastRijndael::encrypt(unsigned char* block, int &length){
	if (block == NULL){
		printf("block null\n");
		return;
	}
	unsigned char* _last_cipher_text;
	unsigned char* _next_block_text;
	if (_mode != ECB){	//allocates temp mem to save last chain block
		_next_block_text = new unsigned char [16];
		_last_cipher_text = new unsigned char [16];
	}
	int blocks = (length / (_block_char_size));
	if (length % _block_char_size != 0){
		blocks++;
	}

	makePadding(block, length, blocks);

	//copy 1 block from block data (should be padded already)
	//unsigned char* _temp_block = new unsigned char [16];
	unsigned char* _temp_block = block;
	
	for (int b = 0; b < blocks; b++){
		_temp_block = &block[b*16];
//		memcpy(_temp_block, &block[b*16], 16);
		switch (_mode){
			case ECB:
				break;		
			case CBC:
				if (b != 0){ 	xorBlock(_temp_block, _last_cipher_text);	}
				else{		xorBlock(_temp_block, _iv);			}				
				break;
			case CFB:
			case OFB:
				if (b != 0){
					memcpy(_next_block_text, _temp_block, 16);	
					memcpy(_temp_block, _last_cipher_text, 16);
				}
				else{
					memcpy(_next_block_text, _temp_block, 16);	
					memcpy(_temp_block, _iv, 16);
				}
				break;	
		}
		encrypt(_temp_block);
		switch (_mode){
			case ECB:
				break;			
			case CBC:
				if (b < blocks-1){	//not last cipher text
					memcpy(_last_cipher_text, _temp_block, 16);
				}
				break;
			case CFB:
				xorBlock(_temp_block, _next_block_text);
				memcpy(_last_cipher_text, _temp_block, 16);
				break;
			case OFB:
				memcpy(_last_cipher_text, _temp_block, 16);
				xorBlock(_temp_block, _next_block_text);
				break;	
		}
	}
	if (_mode != ECB){
		delete[] _last_cipher_text;
		delete[] _next_block_text;
	}
//	delete[] _temp_block;

//old
////	makePadding(block, length, blocks);
//	unsigned char* _temp_shifted_block = new unsigned char [16];	// do inverse matrix, so pointers for char** are in position
//	unsigned char** _temp_block = new unsigned char* [4];
//	for (int b = 0; b < blocks; b++){
//		for (int i = 0; i < 4; i++){
//			memcpy(_temp_shifted_block+i*4, block+i+0+b*16, 1);
//			memcpy(_temp_shifted_block+i*4+1, block+i+4+b*16, 1);
//			memcpy(_temp_shifted_block+i*4+2, block+i+8+b*16, 1);
//			memcpy(_temp_shifted_block+i*4+3, block+i+12+b*16, 1);
//		}
//		for (int i = 0; i < 4; i++){
//			_temp_block[i] = &_temp_shifted_block[i*4];	// tempblock points to tempshiftedblock
//		}
//		switch (_mode){
//			case ECB:	
//				break;
//			case CBC:
//				if (b != 0){	//block is not the first from a chain
//					xorBlock(_temp_block, _last_cipher_text);
//				}
//				else{		//first block
//					xorBlock(_temp_block, _iv);
//				}			
//				break;
//			case CFB:
//			case OFB:
//				if (b != 0){
//					for (int i = 0; i < 4; i++){
//						memcpy(_next_block_text[i], _temp_block[i], 4);	
//						memcpy(_temp_block[i], _last_cipher_text[i], 4);
//					}
//				}
//				else{
//					for (int i = 0; i < 4; i++){
//						memcpy(_next_block_text[i], _temp_block[i], 4);	
//						memcpy(_temp_block[i], _iv[i], 4);
//					}
//				}
//				break;
//		}
///*		for (int i = 0; i < 4; i++){
//			for (int j = 0; j < 4; j++){
//				printf("%x ", _temp_block[i][j]);fflush(stdout);
//			}
//			printf("\n");
//		}*/
//		encrypt(_temp_block);
///*		for (int i = 0; i < 4; i++){
//			for (int j = 0; j < 4; j++){
//				printf("%x", _temp_block[i][j]);fflush(stdout);
//			}
//			printf("\n");
//		}*/
//		switch (_mode){
//			case ECB:
//				break;
//			case CBC:
//				if (b < blocks-1){	//not last cipher text
//					for (int i = 0; i < 4; i++){
//						memcpy(_last_cipher_text[i], _temp_block[i], 4);
//					}
//				}
//				break;
//			case CFB:
//				xorBlock(_temp_block, _next_block_text);
//				for (int i = 0; i < 4; i++){
//					memcpy(_last_cipher_text[i], _temp_block[i], 4);
//				}
//				break;
//			case OFB:
//				for (int i = 0; i < 4; i++){
//					memcpy(_last_cipher_text[i], _temp_block[i], 4);
//				}
//				xorBlock(_temp_block, _next_block_text);
//				break;
//		}
//		for (int i = 0; i < 4; i++){					// redo inverse, to original format position
//			memcpy(block+i*4+b*16, _temp_shifted_block+i+0, 1);
//			memcpy(block+i*4+1+b*16, _temp_shifted_block+i+4, 1);
//			memcpy(block+i*4+2+b*16, _temp_shifted_block+i+8, 1);
//			memcpy(block+i*4+3+b*16, _temp_shifted_block+i+12, 1);
//		}
//	}
//	if (_mode != ECB){
//		for (int i = 0; i < 4; i++){
//			delete[] _last_cipher_text[i];
//			delete[] _next_block_text[i];
//		}
//		delete[] _last_cipher_text;
//		delete[] _next_block_text;
//	}
//	delete[] _temp_block;
//	delete[] _temp_shifted_block;
}

void printBlock(unsigned char* block){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%.2x ", block[j*4+i]);
		}
		printf("\n");
	}
}

void FastRijndael::encrypt(unsigned char* block){
	if (!_initd){
		return;
	}
	_round = 0;
	addRoundKey(block);		
	_round++;
	for (; _round < _nr; _round++){
		subBytes(block);
		shiftRows(block);
		mixColumns(block);
		addRoundKey(block);		
	}
	subBytes(block);
	shiftRows(block);
	addRoundKey(block);		
}

void FastRijndael::removePadding(unsigned char* block, int &length, int blocks){
	if (block[length-1] > 0x00 && block[length-1] < 0x10){
		int i;
		for (i = length-2; i > length-block[length-1]; i--){
			if (block[i] != block[length-1]){
				return;
			}
		//	block[i] = 0x00;
		}
		for (int j = i; j < length; j++){
			block[j] = 0x00;
		}
		length = i;
	}
/*	int _last_block_length = blocks*128/8 - length;
	char pad = _last_block_length;
	for (int i = length; i < (blocks)*128/8; i++){
		block[i] = pad;
	}*/
}


void FastRijndael::decrypt(unsigned char* block, int &length){
	if (block == NULL){
		return;
	}
	unsigned char* _last_cipher_text;
	unsigned char* _next_cipher_text;
	if (_mode != ECB){	//allocates temp mem to save last chain block
		_next_cipher_text = new unsigned char [16];
		_last_cipher_text = new unsigned char [16];
	}
	int blocks = length / (_block_char_size);
	if (length % _block_char_size != 0){
		blocks++;
	}	

	//unsigned char* _temp_block = new unsigned char [16];
	unsigned char* _temp_block = block;
	

	for (int b = 0; b < blocks; b++){
		_temp_block = &block[b*16];
//		memcpy(_temp_block, &block[b*16], 16);
		switch (_mode){		// pre block mode
			case ECB:
				break;
			case CBC:
				memcpy(_last_cipher_text, _next_cipher_text, 16);
				memcpy(_next_cipher_text, _temp_block, 16);
				break;
			case CFB:
			case OFB:
				if (b != 0){
					memcpy(_next_cipher_text, _temp_block, 16);
					memcpy(_temp_block, _last_cipher_text, 16);
				}
				else{
					memcpy(_next_cipher_text, _temp_block, 16);
					memcpy(_temp_block, _iv, 16);
				}
				break;
		}
		switch (_mode){		// decrypt or encrypt
			case ECB:
			case CBC:
				decrypt(_temp_block);
				break;
			case CFB:
			case OFB:
				encrypt(_temp_block);
				break;
		}
		switch (_mode){		// pos block mode
			case ECB:
				break;
			case CBC:
				if (b != 0){
					xorBlock(_temp_block, _last_cipher_text);			
				}
				else{
					xorBlock(_temp_block, _iv);
				}
				break;
			case CFB:
				xorBlock(_temp_block, _next_cipher_text);
				memcpy(_last_cipher_text, _next_cipher_text, 16);
				break;
			case OFB:				
				memcpy(_last_cipher_text, _temp_block, 16);
				xorBlock(_temp_block, _next_cipher_text);
				break;
		}
	}
	if (_mode != ECB){
		delete[] _last_cipher_text;
		delete[] _next_cipher_text;
	}
//	removePadding(block, length, blocks);
//	delete[] _temp_block;

//old
//	unsigned char* _temp_shifted_block = new unsigned char [16];	// do inverse matrix, so pointers for char** are in position
//	unsigned char** _temp_block = new unsigned char* [4];
//	for (int b = 0; b < blocks; b++){
//		for (int i = 0; i < 4; i++){
//			memcpy(_temp_shifted_block+i*4, block+i+0+b*16, 1);
//			memcpy(_temp_shifted_block+i*4+1, block+i+4+b*16, 1);
//			memcpy(_temp_shifted_block+i*4+2, block+i+8+b*16, 1);
//			memcpy(_temp_shifted_block+i*4+3, block+i+12+b*16, 1);
//		}
//		for (int i = 0; i < 4; i++){
//			_temp_block[i] = &_temp_shifted_block[i*4];
//		}
//		switch (_mode){		// pre block mode
//			case ECB:
//				break;
//			case CBC:
//				for (int i = 0; i < 4; i++){
//					memcpy(_last_cipher_text[i], _next_cipher_text[i], 4);
//					memcpy(_next_cipher_text[i], _temp_block[i], 4);
//				}
//				break;
//			case CFB:
//			case OFB:
//				if (b != 0){
//					for (int i = 0; i < 4; i++){
//						memcpy(_next_cipher_text[i], _temp_block[i], 4);
//						memcpy(_temp_block[i], _last_cipher_text[i], 4);
//					}
//				}
//				else{
//					for (int i = 0; i < 4; i++){
//						memcpy(_next_cipher_text[i], _temp_block[i], 4);
//						memcpy(_temp_block[i], _iv[i], 4);
//					}
//				}
//				break;
//		}
//		switch (_mode){		// decrypt or encrypt
//			case ECB:
//			case CBC:
//				decrypt(_temp_block);
//				break;
//			case CFB:
//			case OFB:
//				encrypt(_temp_block);
//				break;
//		}
//		switch (_mode){		// pos block mode
//			case ECB:
//				break;
//			case CBC:
//				if (b != 0){
//					xorBlock(_temp_block, _last_cipher_text);			
//				}
//				else{
//					xorBlock(_temp_block, _iv);
//				}
//				break;
//			case CFB:
//				xorBlock(_temp_block, _next_cipher_text);
//				for (int i = 0; i < 4; i++){
//					memcpy(_last_cipher_text[i], _next_cipher_text[i], 4);
//				}
//				break;
//			case OFB:				
//				for (int i = 0; i < 4; i++){
//					memcpy(_last_cipher_text[i], _temp_block[i], 4);
//				}
//				xorBlock(_temp_block, _next_cipher_text);
//				break;
//		}
//		for (int i = 0; i < 4; i++){
//			memcpy(block+i*4+b*16, _temp_shifted_block+i+0, 1);
//			memcpy(block+i*4+1+b*16, _temp_shifted_block+i+4, 1);
//			memcpy(block+i*4+2+b*16, _temp_shifted_block+i+8, 1);
//			memcpy(block+i*4+3+b*16, _temp_shifted_block+i+12, 1);
//		}
//	}
//	if (_mode != ECB){
//		for (int i = 0; i < 4; i++){
//			delete[] _last_cipher_text[i];
//			delete[] _next_cipher_text[i];
//		}
//		delete[] _next_cipher_text;
//		delete[] _last_cipher_text;
//	}
////	removePadding(block, length, blocks);
//	delete[] _temp_block;
//	delete[] _temp_shifted_block;
}

void FastRijndael::decrypt(unsigned char* block){
	if (!_initd){
		return;
	}
	_round = _nr;
	addRoundKey(block);
	_round--;
	for (; _round > 0; _round--){
		invShiftRows(block);
		invSubBytes(block);
		addRoundKey(block);
		invMixColumns(block);
	}		
	invShiftRows(block);
	invSubBytes(block);
	addRoundKey(block);
}

void FastRijndael::encryptOneRound(unsigned char* block){
	if (!_initd){
		return;
	}
	_round = 0;
#if DEBUG	
	fprintf(STDOUT, "Round %i\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	addRoundKey(block);		
#if DEBUG	
	fprintf(STDOUT, "Round %i after whitening ARK\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	_round++;
	subBytes(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after SB\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	shiftRows(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after SR\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	mixColumns(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after MC\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	addRoundKey(block);		
#if DEBUG	
	fprintf(STDOUT, "Round %i after ARK\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
}

void FastRijndael::decryptOneRound(unsigned char* block){
	if (!_initd){
		return;
	}
	_round = 1;
	addRoundKey(block);
	invMixColumns(block);
	invShiftRows(block);
	invSubBytes(block);
	_round--;
	addRoundKey(block);
}

void FastRijndael::encryptTwoRounds(unsigned char* block){
	if (!_initd){
		return;
	}
	_round = 0;
#if DEBUG	
	fprintf(STDOUT, "Round %i\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	addRoundKey(block);		
#if DEBUG	
	fprintf(STDOUT, "Round %i after whitening ARK\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	_round++;
	subBytes(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after SB\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	shiftRows(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after SR\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	mixColumns(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after MC\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	addRoundKey(block);		
#if DEBUG	
	fprintf(STDOUT, "Round %i after ARK\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	
	_round++;
	subBytes(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after SB\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	shiftRows(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after SR\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	addRoundKeySwappedMCRoundTwo(block);
#if DEBUG	
	fprintf(STDOUT, "Round %i after ARK with k swapped\n", _round-1); for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++){	fprintf(STDOUT, "%x ", block[i][j]); } 	fprintf(STDOUT, "\n");	}
#endif
	mixColumns(block);
}


void FastRijndael::decryptTwoRounds(unsigned char* block){
	if (!_initd){
		return;
	}
	_round = 2;
	addRoundKey(block);
	invMixColumns(block);
	invShiftRows(block);
	invSubBytes(block);
	_round--;
	addRoundKey(block);
	invMixColumns(block);
	invShiftRows(block);
	invSubBytes(block);
	_round--;
	addRoundKey(block);
}
