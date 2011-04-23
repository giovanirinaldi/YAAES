#include "rijndael.h"
#include <cstring>
#include <cstdio>

Rijndael::Rijndael(KeySize ks, BlockSize bs){
	_exp_key = NULL;
	_round = 0;
	_key_size = ks;
	_block_size = bs;
	_nb = bs/32;
	_nk = ks/32;
	switch (_nk){
		case 4:	_nr = 10;	break;
		case 6:	_nr = 12;	break;
		case 8:	_nr = 14;	break;
	}
	_nek = bs/32 * (_nr + 1);	// # of byte columns of expanded key
}

Rijndael::~Rijndael(){
	if (_exp_key){
		for (int i = 0; i < _nek; i++){
			delete[] _exp_key[i];	
		}
		delete[] _exp_key;
		_exp_key = NULL;
	}
}

void Rijndael::makeKey(unsigned char* key){
	if (key == NULL){
		return;
	}
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
}

void Rijndael::makeKey(unsigned char** key){
	if (key == NULL){
		return;
	}
	_exp_key = new unsigned char* [_nek];	
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

unsigned char gmul(unsigned char a, unsigned char b) {
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
					block[i][j] ^= gmul(temp[m], _inv_mix[i][m]);
			}
		}
	}
	delete[] temp;
}

void Rijndael::addRoundKey(unsigned char** block){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			block[i][j] ^= _exp_key[j+_round*4][i];
		}
	}
}

void Rijndael::encrypt(unsigned char* block){
	if (block == NULL){
		return;
	}
	unsigned char* _temp_shifted_block = new unsigned char [16];	// do inverse matrix, so pointes for char** are in position
	for (int i = 0; i < 4; i++){
		memcpy(_temp_shifted_block+i*4, block+i+0, 1);
		memcpy(_temp_shifted_block+i*4+1, block+i+4, 1);
		memcpy(_temp_shifted_block+i*4+2, block+i+8, 1);
		memcpy(_temp_shifted_block+i*4+3, block+i+12, 1);
	}
	unsigned char** _temp_block = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		_temp_block[i] = &_temp_shifted_block[i*4];
	}
	/*for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%c ", _temp_key[i][j]);
		}
		printf("\n");
	}*/
	encrypt(_temp_block);
	for (int i = 0; i < 4; i++){					// redo inverse, to original format position
		memcpy(block+i*4, _temp_shifted_block+i+0, 1);
		memcpy(block+i*4+1, _temp_shifted_block+i+4, 1);
		memcpy(block+i*4+2, _temp_shifted_block+i+8, 1);
		memcpy(block+i*4+3, _temp_shifted_block+i+12, 1);
	}
	delete[] _temp_block;
	delete[] _temp_shifted_block;
}

void Rijndael::encrypt(unsigned char** block){
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


void Rijndael::decrypt(unsigned char* block){
	if (block == NULL){
		return;
	}
	unsigned char* _temp_shifted_block = new unsigned char [16];
	for (int i = 0; i < 4; i++){
		memcpy(_temp_shifted_block+i*4, block+i+0, 1);
		memcpy(_temp_shifted_block+i*4+1, block+i+4, 1);
		memcpy(_temp_shifted_block+i*4+2, block+i+8, 1);
		memcpy(_temp_shifted_block+i*4+3, block+i+12, 1);
	}
	unsigned char** _temp_block = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		_temp_block[i] = &_temp_shifted_block[i*4];
	}
	decrypt(_temp_block);
	for (int i = 0; i < 4; i++){
		memcpy(block+i*4, _temp_shifted_block+i+0, 1);
		memcpy(block+i*4+1, _temp_shifted_block+i+4, 1);
		memcpy(block+i*4+2, _temp_shifted_block+i+8, 1);
		memcpy(block+i*4+3, _temp_shifted_block+i+12, 1);
	}
	delete[] _temp_block;
	delete[] _temp_shifted_block;
}

void Rijndael::decrypt(unsigned char** block){
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
