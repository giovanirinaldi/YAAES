#include "rijndael.h"
#include <cstring>

#include <cstdio>


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

void Rijndael::encrypt(){
}

void Rijndael::decrypt(){
}
