/*#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>*/

#include <cstdio>
#include <cctype>

using namespace std;

#include "fast-rijndael-1d.h"

int mul(int x, int y) {
    int r = 0;
    for (;y!=0;y>>=1,x<<=1)
        if (y&1)
            r+=x;
    return r;
}

unsigned char hexValue(unsigned char &hex){
	if (hex >= 48 && hex <= 57){
		return hex - 48;
	}
	else if (toupper(hex) >= 65 && toupper(hex) <= 70){
		return toupper(hex) - 55;
	}
	else{
		return hex;
	}
}

void hexStringToCharString(unsigned char* hexString, int hexStringLen, unsigned  char* charString){
	for (int i = 0; i < hexStringLen; i=i+2){
		charString[i/2] = hexValue(hexString[i]) * 16 + hexValue(hexString[i+1]);
	}
}

void diff(unsigned char** a, unsigned char** b, unsigned char** r, int minlin = 0, int maxlin = 3, int mincol = 0, int maxcol = 3){
	for (int i = minlin; i <= maxlin; i++){
		for (int j = mincol; j <= maxcol; j++){
			r[i][j] = a[i][j] ^ b[i][j];
		}
	}
}

bool isEqual(unsigned char** a, unsigned char** b){	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (a[i][j] != b[i][j]){
				return false;
			}
		}
	}
	return true;
}

void printEqualBytes(unsigned char** a, unsigned char** b){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (a[i][j] == b[i][j]){
				printf("Has Equal Byte at line %d col %d: %x\n", i, j, a[i][j]);
			}
		}
	}
}

void printBlock1(unsigned char* block, int size){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < size/4; j++){
			printf("%.2x ", block[j*4+i]);
		}
		printf("\n");
	}
}

unsigned char gmulaux(unsigned char a, unsigned char b) {
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

unsigned char gfmult(unsigned char a, unsigned char b) {
	return mult_table[a][b];
}

unsigned char gfdiv(unsigned char a, unsigned char b) {
//	return div_table[a][b];
}

int main (int argc, char *argv[]){

	FastRijndael rijn(FastRijndael::K128, FastRijndael::B128, FastRijndael::CFB);
//	char chKey[33] = "000102030405060708090a0b0c0d0e0f";
	char chKey[33] = "2b7e151628aed2a6abf7158809cf4f3c";
        unsigned char* cKey = new unsigned char [16];
        hexStringToCharString((unsigned char*)chKey, 32, cKey);

	rijn.makeKey(cKey);
	
	char chIV[33] = "000102030405060708090a0b0c0d0e0f";
	unsigned char* cIV = new unsigned char [16];
	hexStringToCharString((unsigned char*)chIV, 32, cIV);

	rijn.setIV(cIV);
	
	char chBlock[33] = "6b000000000000000000000000000000";
        unsigned char* cBlock = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock, 32, cBlock);
	int blockLength = 16;

//	printBlock1(cBlock, 16);	
	rijn.encrypt(cBlock, blockLength);
	printBlock1(cBlock, 16);
//	rijn.decrypt(cBlock);
//	printBlock1(cBlock, 16);
	
	return EXIT_SUCCESS;
}
