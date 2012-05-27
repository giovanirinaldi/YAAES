#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

using namespace std;

#include "../fast-rijndael-1d/fast-rijndael-1d.h"
#include "../attacker/rijndaelattacker.h"

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

void printBlockInline(unsigned char *block){
	for (int i = 0; i < 16; i++){	
		printf("%.2x", block[i]);
	}
	printf("\n");
}

void copyBlock(unsigned char* block_src, unsigned char* block_dest){
	memcpy(block_dest, block_src, 16);
}

int main(){

	FastRijndael rijn(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);
	
//	unsigned char chKey[17] = "essasenhaehfraca";
	char chKey[33] = "000102030405060708090a0b0c0d0e0f";
        unsigned char* cKey = new unsigned char [16];
        hexStringToCharString((unsigned char*)chKey, 32, cKey);

	rijn.makeKey(cKey);

	unsigned char chBlock1[33] = "00112233445566778899aabbccddeeff"; 
//	unsigned char chBlock1[33] = "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"; 	
        unsigned char* cBlock1_plain = new unsigned char [16];
        unsigned char* cBlock1_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock1, 32, cBlock1_plain);
	copyBlock(cBlock1_plain, cBlock1_cipher);
	rijn.encryptTwoRounds(cBlock1_cipher);

	unsigned char chBlock2[33] = "ffeeddccbbaa99887766554433221100"; 
//	unsigned char chBlock2[33] = "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"; 
        unsigned char* cBlock2_plain = new unsigned char [16];
        unsigned char* cBlock2_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock2, 32, cBlock2_plain);
	copyBlock(cBlock2_plain, cBlock2_cipher);
	rijn.encryptTwoRounds(cBlock2_cipher);
	
	unsigned char chBlock3[33] = "778899aabbccddeeff00112233445566"; 
//	unsigned char chBlock3[33] = "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"; 
        unsigned char* cBlock3_plain = new unsigned char [16];
        unsigned char* cBlock3_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock3, 32, cBlock3_plain);
	copyBlock(cBlock3_plain, cBlock3_cipher);
	rijn.encryptTwoRounds(cBlock3_cipher);

	printBlockInline(cBlock1_cipher);
	printBlockInline(cBlock2_cipher);
	printBlockInline(cBlock3_cipher);

	unsigned char** plaintexts_array = new unsigned char* [3];
	plaintexts_array[0] = cBlock1_plain;
	plaintexts_array[1] = cBlock2_plain;
	plaintexts_array[2] = cBlock3_plain;

	unsigned char** ciphertexts_array = new unsigned char* [3];
	ciphertexts_array[0] = cBlock1_cipher;
	ciphertexts_array[1] = cBlock2_cipher;
	ciphertexts_array[2] = cBlock3_cipher;

	unsigned char* k0found = new unsigned char [16];

	RijndaelAttacker rijnAttack;	
	if (rijnAttack.findKeyForTwoRounds(plaintexts_array, ciphertexts_array, 3, k0found, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff)){
		printBlock(k0found);
	}
	else{
		printf("not found\n");
	}

	delete[] plaintexts_array;
	delete[] ciphertexts_array;

	delete[] cKey;
	delete[] cBlock1_plain;
	delete[] cBlock1_cipher;
	delete[] cBlock2_plain;
	delete[] cBlock2_cipher;
	delete[] cBlock3_plain;
	delete[] cBlock3_cipher;
	delete[] k0found;
	rijn.cleanUp();

	return 0;
}

