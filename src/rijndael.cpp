#include "rijndael.h"
#include <cstring>

#include <cstdio>

Rijndael::Rijndael(){
	_exp_key = NULL;
}

Rijndael::~Rijndael(){
	if (_exp_key){
		for (int i = 0; i < 44; i++){
			delete[] _exp_key[i];	
		}
		delete[] _exp_key;
	}
}

void Rijndael::makeKey(unsigned char** key, KeySize ks, BlockSize bs){
	_exp_key = new unsigned char* [44];	
	for (int i = 0; i < 44; i++){
		_exp_key[i] = new unsigned char [4];
	}
	for (int i = 0; i < 4; i++){
		memcpy(_exp_key[i], key[i], 4);
	}
	for (int i = 4; i < 44; i++){
		memcpy(_exp_key[i], _exp_key[i-1], 4);
		if (i % 4 == 0){
			rotWord(_exp_key[i]);
			subWord(_exp_key[i]);
			_exp_key[i][0] ^= _rcon[i/4];	//xor Rcon
		}
		for (int j = 0; j < 4; j++){
			_exp_key[i][j] ^= _exp_key[i-4][j];
		}
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

void Rijndael::shiftRows(unsigned char** block){
	unsigned char* temp = new unsigned char [4];
	for (int i = 1; i < 4; i++){	//row 0 do not shift
		memcpy(temp, block[i], 4);
		memcpy(block[i], temp+i, 4-i);
		memcpy(block[i]+(4-i), temp, i);
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

void Rijndael::addRoundKey(unsigned char** block){
	int round = 1;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			block[i][j] ^= _exp_key[j+round*4][i];
		}
	}
}

void Rijndael::encrypt(unsigned char** block){
}

void Rijndael::decrypt(){
}
