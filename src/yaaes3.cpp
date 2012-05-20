#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

using namespace std;

#include "fast-rijndael-1d/fast-rijndael-1d.h"

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

void printBlock(unsigned char *block){
	for (int i = 0; i < 4; i++){	
		for (int j = 0; j < 4; j++){	
			printf("%.2x", block[j*4+i]);
		}
		printf("\n");
	}
}

int main(){

	FastRijndael rijn(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);
	
//	unsigned char chKey[17] = "essasenhaehfraca";
	char chKey[33] = "00112233445566778899aabbccddeeff";
        unsigned char* cKey = new unsigned char [16];
        hexStringToCharString((unsigned char*)chKey, 32, cKey);

	rijn.makeKey(cKey);
	printBlock(cKey);

	unsigned char chBlock[33] = "00000000000000000000000000000000"; 

        unsigned char* cBlock = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock, 32, cBlock);
	int blockLength = 16;
	
	
	printBlock(cBlock);	
	for (int i = 0; i < 100000000; i++){
		rijn.encryptOneRound(cBlock);
	}
	printBlock(cBlock);	
	return 0;
}

