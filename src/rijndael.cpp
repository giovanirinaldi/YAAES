#include "rijndael.h"
#include <cstring>

#include <cstdio>

Rijndael::Rijndael(){
	_exp_key = NULL;
	_round = 0;
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
/*				if (temp[m] & 0x80){	// antes, primeiro bit mais signficativo era 1
					block[i][j] ^= 0x1b;
				}	*/
				/*if (_mix[i][m] >= 2){
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
				}*/
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

void Rijndael::encrypt(unsigned char** block){
	addRoundKey(block);		
	_round++;
	for (; _round < 10; _round++){
		subBytes(block);
		shiftRows(block);
		mixColumns(block);
		addRoundKey(block);		
	}
	subBytes(block);
	shiftRows(block);
	addRoundKey(block);		
}

void Rijndael::decrypt(unsigned char** block){
	addRoundKey(block);
	_round--;
	for (; _round > 0; _round--){
		invShiftRows(block);
		invSubBytes(block);
		addRoundKey(block);
		invMixColumns(block);
//	for (int i = 0; i < 4; i++){ for (int j = 0; j < 4; j++){ printf("%x ", block[i][j]); } printf("\n"); }
	}		
	invShiftRows(block);
	invSubBytes(block);
	addRoundKey(block);
}
