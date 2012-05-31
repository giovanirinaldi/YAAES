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
#include "../res/x_sbox_diff_coded.h"
#include "../res/y_sbox_diff_coded.h"
#include "../res/new_div_tables.h"
	

unsigned char* k1_12_1;
unsigned char* k1_12_2;
unsigned char* k1_13_1;
unsigned char* k1_13_2;

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

void copyBlock(unsigned char* block_src, unsigned char* block_dest){
	memcpy(block_dest, block_src, 16);
}

bool blocksAreEqual(unsigned char* block1, unsigned char* block2){
	for (int i = 0; i < 16; i++){
		if (block1[i] != block2[i]){
			return false;
		}
	}
	return true;
}

void diff(unsigned char* block1, unsigned char* block2, unsigned char* dest){
	for (int i = 0; i < 16; i++){
		dest[i] = block1[i] ^ block2[i];
	}
}

void findKeyForThreeRounds(FastRijndael* rijn, unsigned char** plaintexts, unsigned char** ciphertexts, int num_texts){
	unsigned char* invCipher1 = new unsigned char[16];
	unsigned char* invCipher2 = new unsigned char[16];
	unsigned char* invCipher3 = new unsigned char[16];
	unsigned char* invCipherDiff12 = new unsigned char[16];
	unsigned char* invCipherDiff13 = new unsigned char[16];
	unsigned char* plainDiff12 = new unsigned char[16];
	unsigned char* plainDiff13 = new unsigned char[16];
	unsigned char* cipherDiff12 = new unsigned char[16];
	unsigned char* cipherDiff13 = new unsigned char[16];
	unsigned char* testBlock1 = new unsigned char[16];
	unsigned char* testBlock2 = new unsigned char[16];

	diff(plaintexts[0], plaintexts[1], plainDiff12);
	//diff(plaintexts[0], plaintexts[2], plainDiff13);
	diff(ciphertexts[0], ciphertexts[1], cipherDiff12);
	//diff(ciphertexts[0], ciphertexts[2], cipherDiff13);
	
	diff(ciphertexts[0], ciphertexts[1], invCipherDiff12);
	//diff(ciphertexts[0], ciphertexts[2], invCipherDiff13);
	rijn->invMixColumns(invCipherDiff12);
	//rijn->invMixColumns(invCipherDiff13);
	rijn->invShiftRows(invCipherDiff12);
	//rijn->invShiftRows(invCipherDiff13);
	
	copyBlock(ciphertexts[0], invCipher1);
	copyBlock(ciphertexts[1], invCipher2);
	//copyBlock(ciphertexts[2], invCipher3);
	rijn->invMixColumns(invCipher1);
	rijn->invMixColumns(invCipher2);
	//rijn->invMixColumns(invCipher3);
	
	unsigned char* tempBlock1 = new unsigned char[16];
	unsigned char* tempBlock2 = new unsigned char[16];
	unsigned char* tempBlock3 = new unsigned char[16];
	unsigned char* tempBlockDiff12 = new unsigned char[16];
	unsigned char* tempBlockDiff13 = new unsigned char[16];
	unsigned char** tempBlock_arrays = new unsigned char* [3];
	tempBlock_arrays[0] = tempBlock1;
	tempBlock_arrays[1] = tempBlock2;
	tempBlock_arrays[2] = tempBlock3;
	

	unsigned char* k0 = new unsigned char[16];
	unsigned char* k1 = new unsigned char[16];
	unsigned char* k2 = new unsigned char[16];
	unsigned char* u2 = new unsigned char[16];

	k1_12_1 = new unsigned char[16];
	k1_12_2 = new unsigned char[16];
	k1_13_1 = new unsigned char[16];
	k1_13_2 = new unsigned char[16];
	
	for (int i = 0; i < 16; i++){
		tempBlock1[i] = 0x00;
		tempBlock2[i] = 0x00;
		tempBlock3[i] = 0x00;
		k0[i] = 0x00;
		k1[i] = 0x00;
		k2[i] = 0x00;
		u2[i] = 0x00;
		tempBlockDiff12[i] = 0x00;
		tempBlockDiff13[i] = 0x00;
	}
	
	int fi = 0;
	int count = 0;
	FastRijndael rijntest(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);

	for (int i = 0; i < 256; i++){
		if (x_sbox_diff[invCipherDiff12[3]*256+i] != 0x00){
			count++;
			printf("%.2x\n", x_sbox_diff[invCipherDiff12[3]*256+i]);
		}
	}
	printf("%d\n", count);
	/*plainDiff12[0] ^= 0x63;	
	plainDiff12[1] ^= 0x63;	
	plainDiff12[2] ^= 0x63;	
	plainDiff12[3] ^= 0x63;	
	
	plainDiff12[4] ^= 0x30;	
	plainDiff12[5] ^= 0x30;	
	plainDiff12[6] ^= 0x30;	//X
	plainDiff12[7] ^= 0x30;	//X

	plainDiff12[8] ^= 0x88;	
	plainDiff12[9] ^= 0x88; //X	
	plainDiff12[10] ^= 0x88; //X	
	plainDiff12[11] ^= 0x88;	

	plainDiff12[12] ^= 0x9a;	
	plainDiff12[13] ^= 0x9a;	
	plainDiff12[14] ^= 0x9a;	
	plainDiff12[15] ^= 0x9a;	*/

//	printBlock(plainDiff12);
	//printBlock(cipherDiff12);
	//printBlock(invCipherDiff12);
	
	delete[] tempBlock1;	
	delete[] tempBlock2;	
	delete[] tempBlock3;	
	delete[] k0;
	delete[] k1;
	delete[] k2;
	delete[] u2;
	delete[] tempBlockDiff12;
	delete[] tempBlockDiff13;
	delete[] tempBlock_arrays;
}

int main(){

	FastRijndael rijn(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);
	
//	unsigned char chKey[17] = "essasenhaehfraca";
	char chKey[33] = "000102030405060708090a0b0c0d0e0f";
        unsigned char* cKey = new unsigned char [16];
        hexStringToCharString((unsigned char*)chKey, 32, cKey);

	rijn.makeKey(cKey);

	unsigned char chBlock1[33] = "00000000000000000000000000000000"; 	
        unsigned char* cBlock1_plain = new unsigned char [16];
        unsigned char* cBlock1_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock1, 32, cBlock1_plain);
	copyBlock(cBlock1_plain, cBlock1_cipher);
	rijn.encryptTwoRounds(cBlock1_cipher);

	unsigned char chBlock2[33] = "01000000000000000000000000000000";
        unsigned char* cBlock2_plain = new unsigned char [16];
        unsigned char* cBlock2_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock2, 32, cBlock2_plain);
	copyBlock(cBlock2_plain, cBlock2_cipher);
	rijn.encryptTwoRounds(cBlock2_cipher);
	
	/*unsigned char chBlock3[33] = "778899aabbccddeeff00112233445566"; 
        unsigned char* cBlock3_plain = new unsigned char [16];
        unsigned char* cBlock3_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock3, 32, cBlock3_plain);
	copyBlock(cBlock3_plain, cBlock3_cipher);
	rijn.encryptTwoRounds(cBlock3_cipher);*/

	/*printBlock(cBlock1_plain);	
	printBlock(cBlock1_cipher);	
	printBlock(cBlock2_plain);	
	printBlock(cBlock2_cipher);	*/
	/*printBlock(cBlock3_plain);	
	printBlock(cBlock3_cipher);	*/

	unsigned char** plaintexts_array = new unsigned char* [2];
	plaintexts_array[0] = cBlock1_plain;
	plaintexts_array[1] = cBlock2_plain;
//	plaintexts_array[2] = cBlock3_plain;

	unsigned char** ciphertexts_array = new unsigned char* [2];
	ciphertexts_array[0] = cBlock1_cipher;
	ciphertexts_array[1] = cBlock2_cipher;
//	ciphertexts_array[2] = cBlock3_cipher;
	
	findKeyForThreeRounds(&rijn, plaintexts_array, ciphertexts_array, 2);

	delete[] plaintexts_array,
	delete[] ciphertexts_array;

	delete[] cKey;
	delete[] cBlock1_plain;
	delete[] cBlock1_cipher;
	delete[] cBlock2_plain;
	delete[] cBlock2_cipher;
	//delete[] cBlock3_plain;
	//delete[] cBlock3_cipher;
	rijn.cleanUp();

	return 0;
}

