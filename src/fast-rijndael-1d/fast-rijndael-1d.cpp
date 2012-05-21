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
	for (int i = 0; i < _nb*4; i++){
		_iv[i] = rand()%256;
	}	
}

void FastRijndael::getIV(unsigned char* iv){
	memcpy(&iv[0], &_iv[0], _nb*4);
}

void FastRijndael::setIV(unsigned char* iv){
	memcpy(&_iv[0], &iv[0], _nb*4);
}

void FastRijndael::makeKey(unsigned char* key){
	if (key == NULL){
		return;
	}

	_exp_key = new unsigned char [_nek*4];	

	memcpy(&_exp_key[0], &key[0], _nk*4);

	for (int i = _nk; i < _nek; i++){
		imult4 = i*4;
		//printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		memcpy(&_exp_key[imult4], &_exp_key[(i-1)*4], 4);
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
		if (_nk == 8){			// 256 bit key	- one subword only
			if ((i-4)%8 == 0){	// between each full step (fullstep -> rot,sub,rcon,xor)
				subWord(&_exp_key[imult4]);
//				printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);	
			}
		}
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
//		printf("%.2x%.2x%.2x%.2x\n", _exp_key[i*4], _exp_key[i*4+1], _exp_key[i*4+2], _exp_key[i*4+3]);
	}
	_initd = true;
}

void FastRijndael::getExpKey(unsigned char* expKey){
	memcpy(expKey, _exp_key, _nek*4);
}
		
void FastRijndael::rotWord(unsigned char* column){
	tempChar = column[0];
	column[0] = column[1];
	column[1] = column[2];
	column[2] = column[3];
	column[3] = tempChar;
}

void FastRijndael::subWord(unsigned char* column){
	column[0] = _sbox[column[0]];
	column[1] = _sbox[column[1]];
	column[2] = _sbox[column[2]];
	column[3] = _sbox[column[3]];
}

void FastRijndael::subBytes(unsigned char* block){
	block[0] = _sbox[block[0]]; block[1] = _sbox[block[1]]; block[2] = _sbox[block[2]]; block[3] = _sbox[block[3]];
	block[4] = _sbox[block[4]]; block[5] = _sbox[block[5]]; block[6] = _sbox[block[6]]; block[7] = _sbox[block[7]];
	block[8] = _sbox[block[8]]; block[9] = _sbox[block[9]]; block[10] = _sbox[block[10]]; block[11] = _sbox[block[11]];
	block[12] = _sbox[block[12]]; block[13] = _sbox[block[13]]; block[14] = _sbox[block[14]]; block[15] = _sbox[block[15]];
}

void FastRijndael::subBytesMainDiagonal(unsigned char* block){
	block[0] = _sbox[block[0]];
	block[5] = _sbox[block[5]];
	block[10] = _sbox[block[10]];
	block[15] = _sbox[block[15]];
}

void FastRijndael::subBytesFirstColumn(unsigned char* block){
	block[0] = _sbox[block[0]];
	block[1] = _sbox[block[1]];
	block[2] = _sbox[block[2]];
	block[3] = _sbox[block[3]];
}

void FastRijndael::invSubBytes(unsigned char* block){
	block[0] = _inv_sbox[block[0]]; block[1] = _inv_sbox[block[1]]; block[2] = _inv_sbox[block[2]]; block[3] = _inv_sbox[block[3]];
	block[4] = _inv_sbox[block[4]]; block[5] = _inv_sbox[block[5]]; block[6] = _inv_sbox[block[6]]; block[7] = _inv_sbox[block[7]];
	block[8] = _inv_sbox[block[8]]; block[9] = _inv_sbox[block[9]]; block[10] = _inv_sbox[block[10]]; block[11] = _inv_sbox[block[11]];
	block[12] = _inv_sbox[block[12]]; block[13] = _inv_sbox[block[13]]; block[14] = _inv_sbox[block[14]]; block[15] = _inv_sbox[block[15]];
}

void FastRijndael::shiftRows(unsigned char* block){
	tempChar = block[5];
	block[5] = block[9]; block[9] = block[13]; block[13] = block[1]; block[1] = tempChar;
	tempChar = block[6]; tempChar2 = block[2];
	block[2] = block[10]; block[6] = block[14]; block[10] = tempChar2; block[14] = tempChar;
	tempChar = block[3];
	block[3] = block[15]; block[15] = block[11]; block[11] = block[7]; block[7] = tempChar;
}

void FastRijndael::shiftRowsMainDiagonal(unsigned char* block){
	block[1] = block[5];
	block[2] = block[10];
	block[3] = block[15];
}

void FastRijndael::invShiftRows(unsigned char* block){
	tempChar = block[5];
	block[5] = block[1]; block[1] = block[13]; block[13] = block[9]; block[9] = tempChar;
	tempChar = block[10]; tempChar2 = block[14];
	block[10] = block[2]; block[14] = block[6]; block[2] = tempChar; block[6] = tempChar2;
	tempChar = block[15];
	block[15] = block[3]; block[3] = block[7]; block[7] = block[11]; block[11] = tempChar;
}

void FastRijndael::mixColumns(unsigned char* block){
	//mult comes from _mix values (2,3,1,1......3,1,1,2);
	memcpy(tempBlock, block, 16);
	
	block[0] = mult_2_table[tempBlock[0]] ^ mult_3_table[tempBlock[1]] ^ tempBlock[2] ^ tempBlock[3];
	block[1] = tempBlock[0] ^ mult_2_table[tempBlock[1]] ^ mult_3_table[tempBlock[2]] ^ tempBlock[3];
	block[2] = tempBlock[0] ^ tempBlock[1] ^ mult_2_table[tempBlock[2]] ^ mult_3_table[tempBlock[3]];
	block[3] = mult_3_table[tempBlock[0]] ^ tempBlock[1] ^ tempBlock[2] ^ mult_2_table[tempBlock[3]];

	block[4] = mult_2_table[tempBlock[4]] ^ mult_3_table[tempBlock[5]] ^ tempBlock[6] ^ tempBlock[7];
	block[5] = tempBlock[4] ^ mult_2_table[tempBlock[5]] ^ mult_3_table[tempBlock[6]] ^ tempBlock[7];
	block[6] = tempBlock[4] ^ tempBlock[5] ^ mult_2_table[tempBlock[6]] ^ mult_3_table[tempBlock[7]];
	block[7] = mult_3_table[tempBlock[4]] ^ tempBlock[5] ^ tempBlock[6] ^ mult_2_table[tempBlock[7]];

	block[8] = mult_2_table[tempBlock[8]] ^ mult_3_table[tempBlock[9]] ^ tempBlock[10] ^ tempBlock[11];
	block[9] = tempBlock[8] ^ mult_2_table[tempBlock[9]] ^ mult_3_table[tempBlock[10]] ^ tempBlock[11];
	block[10] = tempBlock[8] ^ tempBlock[9] ^ mult_2_table[tempBlock[10]] ^ mult_3_table[tempBlock[11]];
	block[11] = mult_3_table[tempBlock[8]] ^ tempBlock[9] ^ tempBlock[10] ^ mult_2_table[tempBlock[11]];

	block[12] = mult_2_table[tempBlock[12]] ^ mult_3_table[tempBlock[13]] ^ tempBlock[14] ^ tempBlock[15];
	block[13] = tempBlock[12] ^ mult_2_table[tempBlock[13]] ^ mult_3_table[tempBlock[14]] ^ tempBlock[15];
	block[14] = tempBlock[12] ^ tempBlock[13] ^ mult_2_table[tempBlock[14]] ^ mult_3_table[tempBlock[15]];
	block[15] = mult_3_table[tempBlock[12]] ^ tempBlock[13] ^ tempBlock[14] ^ mult_2_table[tempBlock[15]];
}


void FastRijndael::mixFirstColumn(unsigned char* block){
	memcpy(tempColumn, &block[0], 4);

	block[0] = mult_2_table[tempColumn[0]] ^ mult_3_table[tempColumn[1]] ^ tempColumn[2] ^ tempColumn[3];
	block[1] = tempColumn[0] ^ mult_2_table[tempColumn[1]] ^ mult_3_table[tempColumn[2]] ^ tempColumn[3];
	block[2] = tempColumn[0] ^ tempColumn[1] ^ mult_2_table[tempColumn[2]] ^ mult_3_table[tempColumn[3]];
	block[3] = mult_3_table[tempColumn[0]] ^ tempColumn[1] ^ tempColumn[2] ^ mult_2_table[tempColumn[3]];
}

void FastRijndael::mixOneColumn(unsigned char* block, int column){
	l0 = column*4; l1 = l0 + 1; l2 = l0 + 2; l3 = l0 + 3;

	memcpy(tempColumn, &block[l0], 4);

	block[l0] = mult_2_table[tempColumn[0]] ^ mult_3_table[tempColumn[1]] ^ tempColumn[2] ^ tempColumn[3];
	block[l1] = tempColumn[0] ^ mult_2_table[tempColumn[1]] ^ mult_3_table[tempColumn[2]] ^ tempColumn[3];
	block[l2] = tempColumn[0] ^ tempColumn[1] ^ mult_2_table[tempColumn[2]] ^ mult_3_table[tempColumn[3]];
	block[l3] = mult_3_table[tempColumn[0]] ^ tempColumn[1] ^ tempColumn[2] ^ mult_2_table[tempColumn[3]];
}

//unsigned char FastRijndael::mult(unsigned char a, unsigned char b) {
//	return mult_table[a][b];
//}

//unsigned char FastRijndael::div(unsigned char a, unsigned char b) {
//	return div_table[a][b];
//}

void FastRijndael::invMixColumns(unsigned char* block){
	//mult comes from _inv_mix values (2,3,1,1......3,1,1,2);

	memcpy(tempBlock, block, 16);
	block[0] = mult_14_table[tempBlock[0]] ^ mult_11_table[tempBlock[1]] ^ mult_13_table[tempBlock[2]] ^ mult_9_table[tempBlock[3]];
	block[1] = mult_9_table[tempBlock[0]] ^ mult_14_table[tempBlock[1]] ^ mult_11_table[tempBlock[2]] ^ mult_13_table[tempBlock[3]];
	block[2] = mult_13_table[tempBlock[0]] ^ mult_9_table[tempBlock[1]] ^ mult_14_table[tempBlock[2]] ^ mult_11_table[tempBlock[3]];
	block[3] = mult_11_table[tempBlock[0]] ^ mult_13_table[tempBlock[1]] ^ mult_9_table[tempBlock[2]] ^ mult_14_table[tempBlock[3]];

	block[4] = mult_14_table[tempBlock[4]] ^ mult_11_table[tempBlock[5]] ^ mult_13_table[tempBlock[6]] ^ mult_9_table[tempBlock[7]];
	block[5] = mult_9_table[tempBlock[4]] ^ mult_14_table[tempBlock[5]] ^ mult_11_table[tempBlock[6]] ^ mult_13_table[tempBlock[7]];
	block[6] = mult_13_table[tempBlock[4]] ^ mult_9_table[tempBlock[5]] ^ mult_14_table[tempBlock[6]] ^ mult_11_table[tempBlock[7]];
	block[7] = mult_11_table[tempBlock[4]] ^ mult_13_table[tempBlock[5]] ^ mult_9_table[tempBlock[6]] ^ mult_14_table[tempBlock[7]];

	block[8] = mult_14_table[tempBlock[8]] ^ mult_11_table[tempBlock[9]] ^ mult_13_table[tempBlock[10]] ^ mult_9_table[tempBlock[11]];
	block[9] = mult_9_table[tempBlock[8]] ^ mult_14_table[tempBlock[9]] ^ mult_11_table[tempBlock[10]] ^ mult_13_table[tempBlock[11]];
	block[10] = mult_13_table[tempBlock[8]] ^ mult_9_table[tempBlock[9]] ^ mult_14_table[tempBlock[10]] ^ mult_11_table[tempBlock[11]];
	block[11] = mult_11_table[tempBlock[8]] ^ mult_13_table[tempBlock[9]] ^ mult_9_table[tempBlock[10]] ^ mult_14_table[tempBlock[11]];

	block[12] = mult_14_table[tempBlock[12]] ^ mult_11_table[tempBlock[13]] ^ mult_13_table[tempBlock[14]] ^ mult_9_table[tempBlock[15]];
	block[13] = mult_9_table[tempBlock[12]] ^ mult_14_table[tempBlock[13]] ^ mult_11_table[tempBlock[14]] ^ mult_13_table[tempBlock[15]];
	block[14] = mult_13_table[tempBlock[12]] ^ mult_9_table[tempBlock[13]] ^ mult_14_table[tempBlock[14]] ^ mult_11_table[tempBlock[15]];
	block[15] = mult_11_table[tempBlock[12]] ^ mult_13_table[tempBlock[13]] ^ mult_9_table[tempBlock[14]] ^ mult_14_table[tempBlock[15]];

}

void FastRijndael::addRoundKey(unsigned char* block){
	register int round_key = _round*16;
/*	for (int i = 0; i < 16; i++){
		block[i] ^= _exp_key[round_key+i];
	}*/
	block[0] ^= _exp_key[round_key]; block[1] ^= _exp_key[round_key+1]; block[2] ^= _exp_key[round_key+2]; block[3] ^= _exp_key[round_key+3]; 
	block[4] ^= _exp_key[round_key+4]; block[5] ^= _exp_key[round_key+5]; block[6] ^= _exp_key[round_key+6]; block[7] ^= _exp_key[round_key+7]; 
	block[8] ^= _exp_key[round_key+8]; block[9] ^= _exp_key[round_key+9]; block[10] ^= _exp_key[round_key+10]; block[11] ^= _exp_key[round_key+11]; 
	block[12] ^= _exp_key[round_key+12]; block[13] ^= _exp_key[round_key+13]; block[14] ^= _exp_key[round_key+14]; block[15] ^= _exp_key[round_key+15]; 
}

void FastRijndael::addNRoundKey(unsigned char* block, int round){
        for (int i = 0; i < 16; i++){
            block[i] ^= _exp_key[i+round*16];
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
/*	for (int i = 0; i < 16; i++){
		a[i] ^= b[i];
	}*/
	a[0] ^= b[0]; a[1] ^= b[1]; a[2] ^= b[2]; a[3] ^= b[3];
	a[4] ^= b[4]; a[5] ^= b[5]; a[6] ^= b[6]; a[7] ^= b[7];
	a[8] ^= b[8]; a[9] ^= b[9]; a[10] ^= b[10]; a[11] ^= b[11];
	a[12] ^= b[12]; a[13] ^= b[13]; a[14] ^= b[14]; a[15] ^= b[15];	
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
}

/*void printBlock(unsigned char* block){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%.2x ", block[j*4+i]);
		}
		printf("\n");
	}
}*/

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

void FastRijndael::encryptNRounds(unsigned char* block, int rounds){
        if (!_initd){
                return;
        }
        _round = 0;
        addRoundKey(block);
        _round++;
        for (; _round <= rounds; _round++){
                if (_round == _nr)	break;
                subBytes(block);
                shiftRows(block);
                mixColumns(block);
                addRoundKey(block);
        }
        if (_round == _nr && rounds != _nr-1){
                subBytes(block);
                shiftRows(block);
                addRoundKey(block);
        }
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
