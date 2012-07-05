#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

using namespace std;

#include "../../Rijndael/fast-rijndael-1d/fast-rijndael-1d.h"
#include "../../Rijndael/attacker/rijndaelattacker.h"

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

	int countfound = 0;
	int  countnotfound = 0;
	FastRijndael rijn(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);
	//for (int i = 0; i < 256; i++){	
	//printf("%d\n", i);
	//for (int j = 0; j < 256; j++){
//	unsigned char chKey[17] = "essasenhaehfraca";				  
	char chKey[33] = "008beed1c90a1461820319c615532f90";
        unsigned char* cKey = new unsigned char [16];
        hexStringToCharString((unsigned char*)chKey, 32, cKey);
//	cKey[1] ^= i;
//	cKey[2] ^= j;

	rijn.makeKey(cKey);
	printBlockInline(cKey);

	unsigned char chBlock1[33] = "0982761b8761c5af6714e92d76e19c92"; 
//	unsigned char cBlock1_plain[17] = "from: alice@acme"; 	
        unsigned char* cBlock1_plain = new unsigned char [16];
        unsigned char* cBlock1_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock1, 32, cBlock1_plain);
	copyBlock(cBlock1_plain, cBlock1_cipher);
	rijn.encryptTwoRounds(cBlock1_cipher);

	unsigned char chBlock2[33] = "cbe9a872b27db198a72b817b9c76119d"; 
//	unsigned char cBlock2_plain[17] = "to: bob@acmecorp"; 
        unsigned char* cBlock2_plain = new unsigned char [16];
        unsigned char* cBlock2_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock2, 32, cBlock2_plain);
	copyBlock(cBlock2_plain, cBlock2_cipher);
	rijn.encryptTwoRounds(cBlock2_cipher);
	
	unsigned char chBlock3[33] = "aa789a9276761bc8d8c9814500318301"; 
	//unsigned char cBlock3_plain[17] = "Have u seen Eve?"; 
        unsigned char* cBlock3_plain = new unsigned char [16];
        unsigned char* cBlock3_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock3, 32, cBlock3_plain);
	copyBlock(cBlock3_plain, cBlock3_cipher);
	rijn.encryptTwoRounds(cBlock3_cipher);

	printBlockInline(cBlock1_plain);
	printBlockInline(cBlock2_plain);
	printBlockInline(cBlock3_plain);
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
	if (rijnAttack.findKeyForTwoRounds(plaintexts_array, ciphertexts_array, 3, k0found, 0x00, 0x00, 0x0a, 0x0a, 0x61, 0x61, 0x82, 0x82, 0x19, 0x19, 0x90, 0x90)){

		printBlock(k0found);
//		countfound++;
	}
	else{
		printf("not found\n");
//		countnotfound++;
	}
//}
//	};

//	printf("%d %d\n", countfound, countnotfound);

/*	delete[] plaintexts_array;
	delete[] ciphertexts_array;

	delete[] cKey;
	delete[] cBlock1_plain;
	delete[] cBlock1_cipher;
	delete[] cBlock2_plain;
	delete[] cBlock2_cipher;
	delete[] cBlock3_plain;
	delete[] cBlock3_cipher;
	delete[] k0found;*/
	rijn.cleanUp();

	return 0;
}

