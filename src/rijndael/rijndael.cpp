#include "rijndael.h"
#include <cstring>
#include <cstdio>
#include <ctime>

#include <QDebug>

#define DEBUG 1
#define STDOUT stdout

Rijndael::Rijndael(KeySize ks, BlockSize bs, Mode mode){
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

Rijndael::~Rijndael(){
	if (_exp_key){
		for (int i = 0; i < _nek; i++){
			delete[] _exp_key[i];	
		}
		delete[] _exp_key;
		_exp_key = NULL;
	}
	if (_mode != ECB){
		for (int i = 0; i < 4; i++){
			delete[] _iv[i];
		}	
		delete[] _iv;
		_iv = NULL;
	}
}

void Rijndael::generateIV(){	
	srand(time(NULL));	
	_iv = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		_iv[i] = new unsigned char [4];
	}
//	printf("iv: ");
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			_iv[i][j] = rand()%256;
	//		printf("%x ", _iv[i][j]);
		}
	}	
//	printf("\n");
}

void Rijndael::getIV(unsigned char** iv){
	for (int i = 0; i < 4; i++){
		memcpy(iv[i], _iv[i], 4);
	}
}

void Rijndael::getIV(unsigned char* iv){
	for (int i = 0; i < 4; i++){
		memcpy(iv+i*4, _iv[i], 4);
	}
}

void Rijndael::setIV(unsigned char** iv){
	for (int i = 0; i < 4; i++){
		memcpy(_iv[i], iv[i], 4);
	}
}

void Rijndael::setIV(unsigned char* iv){
	for (int i = 0; i < 4; i++){
		memcpy(_iv[i], iv+i*4, 4);
	}
}

void Rijndael::makeKey(unsigned char* key){
//	if (key == NULL){
//		return;
//	}
	unsigned char** _temp_key = new unsigned char* [_nk];
	for (int i = 0; i < _nk; i++){
		_temp_key[i] = &key[i*4];
	}
	/*for (int i = 0; i < _nk; i++){
		for (int j = 0; j < 4; j++){
			printf("%x ", _temp_key[i][j]);
		}
		printf("\n");
	}*/
	makeKey(_temp_key);
	delete[] _temp_key;
//	_initd = true;
}

void Rijndael::makeKey(unsigned char** key){
//	if (key == NULL){
//		return;
//	}
	_exp_key = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		_exp_key[i] = new unsigned char [_nek];
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			_exp_key[i][j] = key[i][j];
		}
	}
	
	unsigned char temp;
	for (int j = _nk; j < _nek; j++){
		//copy
		_exp_key[0][j] = _exp_key[0][j-1];
		_exp_key[1][j] = _exp_key[1][j-1];
		_exp_key[2][j] = _exp_key[2][j-1];
		_exp_key[3][j] = _exp_key[3][j-1];
		if (j % _nk == 0){
	//		rotWord(_exp_key[i]);
			temp = _exp_key[0][j];
			_exp_key[0][j] = _exp_key[1][j];
			_exp_key[1][j] = _exp_key[2][j];
			_exp_key[2][j] = _exp_key[3][j];
			_exp_key[3][j] = temp;
	//		subWord(_exp_key[i]);
			for (int i = 0; i < 4; i++){
				_exp_key[i][j] = _sbox[_exp_key[i][j]];
			}
			_exp_key[0][j] ^= _rcon[j/_nk];	//xor Rcon
		}
		for (int i = 0; i < 4; i++){
			_exp_key[i][j] ^= _exp_key[i][j-_nk];
		}		
	}	
	_initd = true;
	
	/*_exp_key = new unsigned char* [_nek];	
	for (int i = 0; i < _nek; i++){
		_exp_key[i] = new unsigned char [4];
	}
	for (int i = 0; i < _nk; i++){
		memcpy(_exp_key[i], key[i], 4);
	}
	for (int i = _nk; i < _nek; i++){
		memcpy(_exp_key[i], _exp_key[i-1], 4);
		if (_nk == 8){			// 256 bit key	- one subword only
			if ((i-4)%8 == 0){	// between each full step (fullstep -> rot,sub,rcon,xor)
				subWord(_exp_key[i]);
			}
		}
		if (i % _nk == 0){
			rotWord(_exp_key[i]);
			subWord(_exp_key[i]);
			_exp_key[i][0] ^= _rcon[i/_nk];	//xor Rcon
		}
		for (int j = 0; j < 4; j++){
			_exp_key[i][j] ^= _exp_key[i-_nk][j];
		}
//		printf("%x%x%x%x\n", _exp_key[i][0], _exp_key[i][1], _exp_key[i][2], _exp_key[i][3]);
	}
	_initd = true;*/
}
		
void Rijndael::rotWord(unsigned char* column){
	unsigned char temp = column[0];
	column[0] = column[1];
	column[1] = column[2];
	column[2] = column[3];
	column[3] = temp;
}

void Rijndael::subWord(unsigned char* column){
	for (int i = 0; i < 4; i++){
		column[i] = _sbox[column[i]];
	}
}

void Rijndael::subBytes(unsigned char** block){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			block[i][j] = _sbox[block[i][j]];
		}
	}
}

void Rijndael::subBytesMainDiagonal(unsigned char** block){
	for (int i = 0; i < 4; i++){
		block[i][i] = _sbox[block[i][i]];
	}
}

void Rijndael::invSubBytes(unsigned char** block){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			block[i][j] = _inv_sbox[block[i][j]];
		}
	}
}

void Rijndael::shiftRows(unsigned char** block){
	unsigned char* temp = new unsigned char [4];
	for (int i = 1; i < 4; i++){	//row 0 do not shift
		memcpy(temp, block[i], 4);
		memcpy(block[i], temp+i, 4-i);
		memcpy(block[i]+(4-i), temp, i);
	}
	delete[] temp;
}

void Rijndael::shiftRowsMainDiagonal(unsigned char** block){
	block[1][0] = block[1][1];
	block[2][0] = block[2][2];
	block[3][0] = block[3][3];
}

void Rijndael::invShiftRows(unsigned char** block){
	unsigned char* temp = new unsigned char [4];
	for (int i = 1; i < 4; i++){	//row 0 do not shift
		memcpy(temp, block[i], 4);
		memcpy(block[i], temp+(4-i), i);
		memcpy(block[i]+i, temp, 4-i);
	}
	delete[] temp;
}

void Rijndael::mixColumns(unsigned char** block){
	unsigned char* temp = new unsigned char [4];	//utilizado para guardar coluna atual
	for (int j = 0; j < 4; j++){
		memcpy(temp, &block[0][j], 1);
		memcpy(temp+1, &block[1][j], 1);
		memcpy(temp+2, &block[2][j], 1);
		memcpy(temp+3, &block[3][j], 1);
		for (int i = 0; i < 4; i++){
			block[i][j] = 0x00;
			for (int m = 0; m < 4; m ++){
				if (_mix[i][m] >= 2){
					block[i][j] ^= temp[m] << 1;
					if (_mix[i][m] == 3){
						block[i][j] ^= temp[m];
					}
					if (temp[m] & 0x80){	// antes, primeiro bit mais signficativo era 1
						block[i][j] ^= 0x1b;
					}	
				}		
				else{
					block[i][j] ^= temp[m];
				}
			}
		}
	}
	delete[] temp;
}

void Rijndael::mixOneColumn(unsigned char** block, int column){
	unsigned char* temp = new unsigned char [4];	//utilizado para guardar coluna atual
	memcpy(temp, &block[0][column], 1);
	memcpy(temp+1, &block[1][column], 1);
	memcpy(temp+2, &block[2][column], 1);
	memcpy(temp+3, &block[3][column], 1);
	for (int i = 0; i < 4; i++){
		block[i][column] = 0x00;
		for (int m = 0; m < 4; m ++){
			if (_mix[i][m] >= 2){
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
			}
		}
	}
	delete[] temp;
}

unsigned char Rijndael::gmul(unsigned char a, unsigned char b) {
	unsigned char p = 0;
	unsigned char counter;
	unsigned char hi_bit_set;
	for(counter = 0; counter < 8; counter++) {
		if((b & 1) == 1) 
			p ^= a;
		hi_bit_set = (a & 0x80);
		a <<= 1;
		if(hi_bit_set == 0x80) 
			a ^= 0x1b;		
		b >>= 1;
	}
	return p;
}


void Rijndael::invMixColumns(unsigned char** block){
	unsigned char* temp = new unsigned char [4];	//utilizado para guardar coluna atual
	for (int j = 0; j < 4; j++){
		memcpy(temp, &block[0][j], 1);
		memcpy(temp+1, &block[1][j], 1);
		memcpy(temp+2, &block[2][j], 1);
		memcpy(temp+3, &block[3][j], 1);
		for (int i = 0; i < 4; i++){
			block[i][j] = 0x00;
			for (int m = 0; m < 4; m ++){
					block[i][j] ^= gmul(temp[m], _inv_mix[i][m]);	// this gmul totally sucks at performance. thinking about static pre-calculated tables.
			}
		}
	}
	delete[] temp;
}

void Rijndael::addRoundKey(unsigned char** block){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			//block[i][j] ^= _exp_key[j+_round*4][i];	//this is why the inverse matrix of key actually works with the (not-inversed) block text
			block[i][j] ^= _exp_key[i][j+_round*4];
		}
	}
}

void Rijndael::addNRoundKey(unsigned char** block, int round){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			//block[i][j] ^= _exp_key[j+_round*4][i];	//this is why the inverse matrix of key actually works with the (not-inversed) block text
			block[i][j] ^= _exp_key[i][j+round*4];
		}
	}
}


void Rijndael::addRoundKeySwappedMCRoundTwo(unsigned char** block){
	unsigned char** temp_exp_key = new unsigned char*[4];
	for (int i = 0; i < 4; i++){
		temp_exp_key[i] = new unsigned char[4];
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			temp_exp_key[i][j] = _exp_key[j+2*4][i];
		}
	}
	invMixColumns(temp_exp_key);
#if DEBUG
	printf("k2 with invMixColumns (for swapping, at round 2, of MC with last ARK)\n");
#endif
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			block[i][j] ^= temp_exp_key[i][j];	//this is why the inverse matrix of key actually works with the (not-inversed) block text
#if DEBUG
			printf("%.2x ", temp_exp_key[i][j]);
#endif
		}
#if DEBUG
		printf("\n");
#endif
	}
}

void Rijndael::xorBlock(unsigned char** a, unsigned char** b){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			a[i][j] ^= b[i][j];
		}
	}
}

void Rijndael::makePadding(unsigned char* block, int &length, int blocks){
	char pad = blocks*128/8 - length;
	int i;
	for (i = length; i < (blocks)*128/8; i++){
		block[i] = pad;
	}
	length = i;
}

void Rijndael::encrypt(unsigned char* block, int &length){
	if (block == NULL){
		printf("block null\n");
		return;
	}
	unsigned char** _last_cipher_text;
	unsigned char** _next_block_text;
	if (_mode != ECB){	//allocates temp mem to save last chain block
		_next_block_text = new unsigned char* [4];
		_last_cipher_text = new unsigned char* [4];
		for (int i = 0; i < 4; i++){
			_next_block_text[i] = new unsigned char [4];
			_last_cipher_text[i] = new unsigned char [4];
		}
	}
	int blocks = (length / (_block_char_size));
	if (length % _block_char_size != 0){
		blocks++;
	}
//	makePadding(block, length, blocks);
	unsigned char* _temp_shifted_block = new unsigned char [16];	// do inverse matrix, so pointers for char** are in position
	unsigned char** _temp_block = new unsigned char* [4];
	for (int b = 0; b < blocks; b++){
		for (int i = 0; i < 4; i++){
			memcpy(_temp_shifted_block+i*4, block+i+0+b*16, 1);
			memcpy(_temp_shifted_block+i*4+1, block+i+4+b*16, 1);
			memcpy(_temp_shifted_block+i*4+2, block+i+8+b*16, 1);
			memcpy(_temp_shifted_block+i*4+3, block+i+12+b*16, 1);
		}
		for (int i = 0; i < 4; i++){
			_temp_block[i] = &_temp_shifted_block[i*4];	// tempblock points to tempshiftedblock
		}
		switch (_mode){
			case ECB:	
				break;
			case CBC:
				if (b != 0){	//block is not the first from a chain
					xorBlock(_temp_block, _last_cipher_text);
				}
				else{		//first block
					xorBlock(_temp_block, _iv);
				}			
				break;
			case CFB:
			case OFB:
				if (b != 0){
					for (int i = 0; i < 4; i++){
						memcpy(_next_block_text[i], _temp_block[i], 4);	
						memcpy(_temp_block[i], _last_cipher_text[i], 4);
					}
				}
				else{
					for (int i = 0; i < 4; i++){
						memcpy(_next_block_text[i], _temp_block[i], 4);	
						memcpy(_temp_block[i], _iv[i], 4);
					}
				}
				break;
		}
/*		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				printf("%x ", _temp_block[i][j]);fflush(stdout);
			}
			printf("\n");
		}*/
		encrypt(_temp_block);
/*		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				printf("%x", _temp_block[i][j]);fflush(stdout);
			}
			printf("\n");
		}*/
		switch (_mode){
			case ECB:
				break;
			case CBC:
				if (b < blocks-1){	//not last cipher text
					for (int i = 0; i < 4; i++){
						memcpy(_last_cipher_text[i], _temp_block[i], 4);
					}
				}
				break;
			case CFB:
				xorBlock(_temp_block, _next_block_text);
				for (int i = 0; i < 4; i++){
					memcpy(_last_cipher_text[i], _temp_block[i], 4);
				}
				break;
			case OFB:
				for (int i = 0; i < 4; i++){
					memcpy(_last_cipher_text[i], _temp_block[i], 4);
				}
				xorBlock(_temp_block, _next_block_text);
				break;
		}
		for (int i = 0; i < 4; i++){					// redo inverse, to original format position
			memcpy(block+i*4+b*16, _temp_shifted_block+i+0, 1);
			memcpy(block+i*4+1+b*16, _temp_shifted_block+i+4, 1);
			memcpy(block+i*4+2+b*16, _temp_shifted_block+i+8, 1);
			memcpy(block+i*4+3+b*16, _temp_shifted_block+i+12, 1);
		}
	}
	if (_mode != ECB){
		for (int i = 0; i < 4; i++){
			delete[] _last_cipher_text[i];
			delete[] _next_block_text[i];
		}
		delete[] _last_cipher_text;
		delete[] _next_block_text;
	}
	delete[] _temp_block;
	delete[] _temp_shifted_block;
}

void Rijndael::encrypt(unsigned char** block){
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

void Rijndael::encryptNRounds(unsigned char** block, int rounds){
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

void Rijndael::removePadding(unsigned char* block, int &length, int blocks){
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


void Rijndael::decrypt(unsigned char* block, int &length){
	if (block == NULL){
		return;
	}
	unsigned char** _last_cipher_text;
	unsigned char** _next_cipher_text;
	if (_mode != ECB){	//allocates temp mem to save last chain block
		_next_cipher_text = new unsigned char* [4];
		_last_cipher_text = new unsigned char* [4];
		for (int i = 0; i < 4; i++){
			_last_cipher_text[i] = new unsigned char [4];
			_next_cipher_text[i] = new unsigned char [4];
		}
	}
	int blocks = length / (_block_char_size);
	if (length % _block_char_size != 0){
		blocks++;
	}	
	unsigned char* _temp_shifted_block = new unsigned char [16];	// do inverse matrix, so pointers for char** are in position
	unsigned char** _temp_block = new unsigned char* [4];
	for (int b = 0; b < blocks; b++){
		for (int i = 0; i < 4; i++){
			memcpy(_temp_shifted_block+i*4, block+i+0+b*16, 1);
			memcpy(_temp_shifted_block+i*4+1, block+i+4+b*16, 1);
			memcpy(_temp_shifted_block+i*4+2, block+i+8+b*16, 1);
			memcpy(_temp_shifted_block+i*4+3, block+i+12+b*16, 1);
		}
		for (int i = 0; i < 4; i++){
			_temp_block[i] = &_temp_shifted_block[i*4];
		}
		switch (_mode){		// pre block mode
			case ECB:
				break;
			case CBC:
				for (int i = 0; i < 4; i++){
					memcpy(_last_cipher_text[i], _next_cipher_text[i], 4);
					memcpy(_next_cipher_text[i], _temp_block[i], 4);
				}
				break;
			case CFB:
			case OFB:
				if (b != 0){
					for (int i = 0; i < 4; i++){
						memcpy(_next_cipher_text[i], _temp_block[i], 4);
						memcpy(_temp_block[i], _last_cipher_text[i], 4);
					}
				}
				else{
					for (int i = 0; i < 4; i++){
						memcpy(_next_cipher_text[i], _temp_block[i], 4);
						memcpy(_temp_block[i], _iv[i], 4);
					}
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
				for (int i = 0; i < 4; i++){
					memcpy(_last_cipher_text[i], _next_cipher_text[i], 4);
				}
				break;
			case OFB:				
				for (int i = 0; i < 4; i++){
					memcpy(_last_cipher_text[i], _temp_block[i], 4);
				}
				xorBlock(_temp_block, _next_cipher_text);
				break;
		}
		for (int i = 0; i < 4; i++){
			memcpy(block+i*4+b*16, _temp_shifted_block+i+0, 1);
			memcpy(block+i*4+1+b*16, _temp_shifted_block+i+4, 1);
			memcpy(block+i*4+2+b*16, _temp_shifted_block+i+8, 1);
			memcpy(block+i*4+3+b*16, _temp_shifted_block+i+12, 1);
		}
	}
	if (_mode != ECB){
		for (int i = 0; i < 4; i++){
			delete[] _last_cipher_text[i];
			delete[] _next_cipher_text[i];
		}
		delete[] _next_cipher_text;
		delete[] _last_cipher_text;
	}
//	removePadding(block, length, blocks);
	delete[] _temp_block;
	delete[] _temp_shifted_block;
}

void Rijndael::decrypt(unsigned char** block){
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

void Rijndael::encryptOneRound(unsigned char** block){
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

void Rijndael::decryptOneRound(unsigned char** block){
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

void Rijndael::encryptTwoRounds(unsigned char** block){
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


void Rijndael::decryptTwoRounds(unsigned char** block){
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
