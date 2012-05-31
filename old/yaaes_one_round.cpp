#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include <cstring>
#include <cctype>
//#include <gtkmm.h>
#include <iostream>
using namespace std;

#include "rijndael/rijndael.h"

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

void diff(unsigned char** a, unsigned char** b, unsigned char** r){	// a - b (or b - a, the same, we just don't want negative values =) = r
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
/*			if (a[i][j] > b[i][j]){
				r[i][j] = a[i][j] - b[i][j];
			}
			else{
				r[i][j] = b[i][j] - a[i][j];
			}*/
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

void printBlock(unsigned char** block){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%x ", block[i][j]);
		}
		printf("\n");
	}
}

int main (int argc, char *argv[]){
	//Rijndael r(Rijndael::K128, Rijndael::B128);
	//std::string key = "essasenhaehfraca";
	//std::string hBlock = "00112233445566778899aabbccddeeff";
	//546578746F2070617261207465737465";
	//char chBlock[65] = "00112233445566778899aabbccddeeff00112233445566778899aabbccddeeff";
//	char notABlock[] = "001122334455667788990a0b0c0d0e0f0011223344556677";
//	unsigned char cnotABlock[32];
	//hexStringToCharString((unsigned char*)notABlock, 20, cnotABlock);
	char chKey[33] = "000102030405060708090a0b0c0d0e0f";			//coluna 1 00010203 linha 1 0004080c
	unsigned char cKey[16];
	hexStringToCharString((unsigned char*)chKey, 32, cKey);
	//r.makeKey(cKey);	
//	hexStringToCharString((unsigned char*)notABlock, 36, cnotABlock);
//	unsigned char cBlock[29] = "1234567890123456abcdefghijkl";
/*	unsigned char hblock[65] = "6f90774ba0d642bbba84664e38e16a5d91828f15bee4312a4a8f54a69c949964";
	unsigned char chblock[33];
	hexStringToCharString((unsigned char*)hblock, 64, chblock);
	unsigned char hiv[33] = "702265631d1f84e24dc3ec5edf735567";
	unsigned char civ[17];
	hexStringToCharString((unsigned char*)hiv, 32, civ);*/
//	unsigned char* paddBlock = new unsigned char [16];		//pad pos hextochar
//	int length = 14;
//	char pad = 16 - length;	//16 == blocksize;
//	memcpy(paddBlock, cnotABlock, length);
	//char pad = padnum;
/*	for (int l = length; l < 16; l++){
		cnotABlock[l] = pad;
	}
	for (int i = 0; i < 32; i++){
		printf("%x ", cBlock[i]);
	}
	printf("\n");*/
		
//	int length = 32;	
	//timeval t1, t2;
	//gettimeofday(&t1, 0);
	unsigned char** a_plain = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		a_plain[i] = new unsigned char[4];
	}
	unsigned char a_plain_char[17] = "AoqJQ2d4mSI1JSoc"; 
	for (int i = 0; i < 4; i++){
		memcpy(a_plain[i], &a_plain_char[i*4], 4);
	}
	Rijndael r(Rijndael::K128, Rijndael::B128, Rijndael::ECB);
	r.makeKey(cKey);	
	r.encryptOneRound(a_plain);	

	unsigned char** b_plain = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		b_plain[i] = new unsigned char[4];
	}
	unsigned char b_plain_char[17] = "1l4PO10j1nN3AU8s"; 
	for (int i = 0; i < 4; i++){
		memcpy(b_plain[i], &b_plain_char[i*4], 4);
	}
	r.encryptOneRound(b_plain);	


	//copy the original, so we have plain and cipher texts in hexa
	unsigned char** a_cipher = a_plain;
	unsigned char** b_cipher = b_plain;
	a_plain = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		a_plain[i] = new unsigned char[4];
	}
	for (int i = 0; i < 4; i++){
		memcpy(a_plain[i], &a_plain_char[i*4], 4);
	}
	b_plain = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		b_plain[i] = new unsigned char[4];
	}
	for (int i = 0; i < 4; i++){
		memcpy(b_plain[i], &b_plain_char[i*4], 4);
	}
	
	printf("--------------\n");
	printf("A plain\n");
	printBlock(a_plain);
	printf("B plain\n");
	printBlock(b_plain);
	printf("A cipher\n");
	printBlock(a_cipher);
	printf("B cipher\n");
	printBlock(b_cipher);
	printf("--------------\n");
	
	//diff of ciphertexts
	unsigned char** ab_cipher_diff = new unsigned char* [4];
	unsigned char** ab_plain_diff = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		ab_cipher_diff[i] = new unsigned char[4];
		ab_plain_diff[i] = new unsigned char[4];
	}
	diff(a_plain, b_plain, ab_plain_diff);
	diff(a_cipher, b_cipher, ab_cipher_diff);
	
	printf("--------------\n");
	printf("AB Plain diff\n");
	printBlock(ab_plain_diff);
	printf("AB Cipher diff\n");
	printBlock(ab_cipher_diff);	
	printf("--------------\n");

	r.invMixColumns(ab_cipher_diff);
	r.invShiftRows(ab_cipher_diff);
		
	printf("--------------\n");
	printf("AB Cipher diff after invMC and invSR\n");
	printBlock(ab_cipher_diff);	
	printf("--------------\n");

	//alloc possibilities matrix. for each position (16 pos total), 2 posibilities of 1 byte key
	unsigned char*** pos = new unsigned char**[4];
	for (int i = 0; i < 4; i++){
		pos[i] = new unsigned char*[4];
		for (int j = 0; j < 4; j++){
			pos[i][j] = new unsigned char[2];
		}
	}	
	unsigned char a, b;
	int count = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			a = ab_plain_diff[i][j];
			b = ab_cipher_diff[i][j];
			for (unsigned char x = 0x00; x <= 0xff; x=x+0x01){
				for (unsigned char y = 0x00; y <= 0xff; y=y+0x01){
					if (((x^y) == a) && ((_sbox[x]^_sbox[y]) == b)){
//						printf("sbox %x (%x) xor sbox %x (%x) == %x (%x) \n", x, _sbox[x], y, _sbox[y], a, b);
						pos[i][j][0] = x;
						pos[i][j][1] = y;						
						count++;
					}
					if (y == 0xff)	break;
				}
				if (x == 0xff)	break;
			}
		}
	}

	Rijndael testr;
	unsigned char** testkey = new unsigned char*[4];
	for (int i = 0; i < 4; i++){
		testkey[i] = new unsigned char[4];
	}
	unsigned char** temp_plain = new unsigned char*[4];
	for (int i = 0; i < 4; i++){
		temp_plain[i] = new unsigned char[4];
	}
	
	for (int i = 0; i < 65536; i++){
		for (int k = 0; k < 4; k++){
			for (int j = 0; j < 4; j++){
				temp_plain[k][j] = a_plain[k][j];
			}
		}
		if (i & 1)	testkey[0][0] = pos[0][0][0] ^ a_plain[0][0];
		else 		testkey[0][0] = pos[0][0][1] ^ a_plain[0][0];
		
		if (i & 2)	testkey[1][0] = pos[0][1][0] ^ a_plain[0][1];
		else 		testkey[1][0] = pos[0][1][1] ^ a_plain[0][1];
	
		if (i & 4)	testkey[2][0] = pos[0][2][0] ^ a_plain[0][2];
		else 		testkey[2][0] = pos[0][2][1] ^ a_plain[0][2];
	
		if (i & 8)	testkey[3][0] = pos[0][3][0] ^ a_plain[0][3];
		else 		testkey[3][0] = pos[0][3][1] ^ a_plain[0][3];
		
		if (i & 16)	testkey[0][1] = pos[1][0][0] ^ a_plain[1][0];
		else 		testkey[0][1] = pos[1][0][1] ^ a_plain[1][0];
		
		if (i & 32)	testkey[1][1] = pos[1][1][0] ^ a_plain[1][1];
		else 		testkey[1][1] = pos[1][1][1] ^ a_plain[1][1];
	
		if (i & 64)	testkey[2][1] = pos[1][2][0] ^ a_plain[1][2];
		else 		testkey[2][1] = pos[1][2][1] ^ a_plain[1][2];
	
		if (i & 128)	testkey[3][1] = pos[1][3][0] ^ a_plain[1][3];
		else 		testkey[3][1] = pos[1][3][1] ^ a_plain[1][3];
		
		if (i & 256)	testkey[0][2] = pos[2][0][0] ^ a_plain[2][0];
		else 		testkey[0][2] = pos[2][0][1] ^ a_plain[2][0];
		
		if (i & 512)	testkey[1][2] = pos[2][1][0] ^ a_plain[2][1];
		else 		testkey[1][2] = pos[2][1][1] ^ a_plain[2][1];
	
		if (i & 1024)	testkey[2][2] = pos[2][2][0] ^ a_plain[2][2];
		else 		testkey[2][2] = pos[2][2][1] ^ a_plain[2][2];
	
		if (i & 2048)	testkey[3][2] = pos[2][3][0] ^ a_plain[2][3];
		else 		testkey[3][2] = pos[2][3][1] ^ a_plain[2][3];

		if (i & 4096)	testkey[0][3] = pos[3][0][0] ^ a_plain[3][0];
		else 		testkey[0][3] = pos[3][0][1] ^ a_plain[3][0];
		
		if (i & 8192)	testkey[1][3] = pos[3][1][0] ^ a_plain[3][1];
		else 		testkey[1][3] = pos[3][1][1] ^ a_plain[3][1];
	
		if (i & 16384)	testkey[2][3] = pos[3][2][0] ^ a_plain[3][2];
		else 		testkey[2][3] = pos[3][2][1] ^ a_plain[3][2];
	
		if (i & 32768)	testkey[3][3] = pos[3][3][0] ^ a_plain[3][3];
		else 		testkey[3][3] = pos[3][3][1] ^ a_plain[3][3];

		r.makeKey(testkey);

/*		for (int k = 0; k < 4; k++){
			for (int j = 0; j < 4; j++){
				printf("%.2x ", testkey[k][j]);
			}
			printf("\n");
		}
		sleep(2);*/
		r.encryptOneRound(temp_plain);	
		if (isEqual(temp_plain, a_cipher)){
			printf("key found at:\n");
			for (int k = 0; k < 4; k++){
				for (int j = 0; j < 4; j++){
					printf("%.2x ", testkey[k][j]);
				}
				printf("\n");
			}	
			break;
		}
	}
//	printf("count = %d\n", count);

		
/*	unsigned char a_plain_byte;
	unsigned char b_plain_byte;
	unsigned char ab_cipher_byte_diff;	
	unsigned char temp_a, temp_b, temp_ab_diff;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			unsigned char a_plain_byte = a_plain[i][j];
			unsigned char b_plain_byte = b_plain[i][j];
			ab_cipher_byte_diff = ab_cipher_diff[i][j];	
			for (int p = 0; p < 256; p++){
				temp_a = _sbox[a_plain_byte + p];
				temp_b = _sbox[b_plain_byte + p];
				temp_ab_diff = (temp_a > temp_b) ? (temp_a - temp_b) : (temp_b - temp_a);
				if (temp_ab_diff == ab_cipher_byte_diff){
					printf("One candidate pair: %x and %x at %d make %x and %x with diff of %x\n", a_plain_byte, b_plain_byte, p, a_cipher[i][j], b_cipher[i][j], ab_cipher_byte_diff);
				}
			}
			printf("---------\n");
		}
	}*/

	//check if sbox input diff equals output diff
	//create a array of 256 positions (all possible diff input blocks for sbox, beggining from plaintext diff
/*	unsigned char*** a_diff_block_array = new unsigned char** [256];
	unsigned char*** b_diff_block_array = new unsigned char** [256];
	for (int p = 0; p < 256; p++){
		unsigned char** a_temp_block = new unsigned char* [4];
		unsigned char** b_temp_block = new unsigned char* [4];
		for (int i = 0; i < 4; i++){
			a_temp_block[i] = new unsigned char[4];
			b_temp_block[i] = new unsigned char[4];
		}
		a_diff_block_array[p] = a_temp_block;
		b_diff_block_array[p] = b_temp_block;		
	}
	
	for (int p = 0; p < 256; p++){
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				a_diff_block_array[p][i][j] = a_plain[i][j]+p;				
				b_diff_block_array[p][i][j] = b_plain[i][j]+p;
			}
		}
	}*/
	

/*	unsigned char** temp = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		temp[i] = new unsigned char[4];
	}
	for (int p = 0; p < 256; p++){
//		printf("-------diff blocks %d----------\n", p);
		r.subBytes(a_diff_block_array[p]);
		//printBlock(a_diff_block_array[p]);
		r.subBytes(b_diff_block_array[p]);
		//printBlock(b_diff_block_array[p]);
		diff(a_diff_block_array[p], b_diff_block_array[p], temp);
//		printBlock(temp);
//		printBlock(ab_cipher_diff);
	//	printEqualBytes(temp, ab_cipher_diff);
//		sleep(5);
//		printf("------------------\n");
	}	*/
	
	
	

/*	r.encrypt(cBlock, length);
	unsigned char* iv = new unsigned char [16];
	r.getIV(iv);
	printf("iv: ");
	for (int i = 0; i < 16; i++){
		printf("%x ", iv[i]);
	}
	printf("\nout crypt: ");
	for (int i = 0; i < length; i++){
		printf("%x ", cBlock[i]);
	}
	printf("\n");*/
	//r.setIV(civ);
	//r.decrypt(chblock, length);
//	gettimeofday(&t2, 0);
	//printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
/*	for (int i = 0; i < length; i++){
		printf("%x", chblock[i]);
	}
	printf(" of length %d\n", length);*/
//	std::string block = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	//printf("%d\n", block.length());
	//hexStringToCharString(chBlock, 32, cBlock);	
	//hexStringToCharString((unsigned char*)hBlock.c_str(), hBlock.length(), (unsigned char*)block.c_str());
	//r.makeKey(key.c_str());
	//printf("%d\n", block.length());
	//r.encrypt((unsigned char*)block.c_str());
	/*printf("%d\n", block.length());
	for (int i = 0; i < block.length(); i++){
		printf("%c ", block[i]);
	}*/
//	printf("\n");
//	timeval t1, t2;
/*	char input[1024];
	char ch[Rijndael::K128/8];
	unsigned char uch[Rijndael::K128/8];
	signed char sch[Rijndael::K128/8];*/
//	unsigned char a[5] = "abcd";
//	if (fgets(input, 16+1, stdin)){
//		if (sscanf(input, "%s", uch) == 1){
			//printf("%d\n", a[0]);
//		}
//	}
//	printf("%d\n", a);
//	gettimeofday(&t1, 0);
//	r.rotWord(a);
//	gettimeofday(&t2, 0);
/*	long mtime, seconds, useconds;
	seconds = t2.tv_sec - t1.tv_sec;
	useconds = t2.tv_usec - t1.tv_usec;
	mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	printf("%ld microseconds\n", mtime);
	printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);*/
//	printf("%d\n", _sbox[0]);
/*	unsigned char bk_round1 [4][4] = {
		{ 0x19, 0xa0, 0x9a, 0xe9 },
		{ 0x3d, 0xf4, 0xc6, 0xf8 },
		{ 0xe3, 0xe2, 0x8d, 0x48 },
		{ 0xbe, 0x2b, 0x2a, 0x08 }
	};
	unsigned char bk_round0 [4][4] = {
		{ 0x32, 0x88, 0x31, 0xe0 },
		{ 0x43, 0x5a, 0x31, 0x37 },
		{ 0xf6, 0x30, 0x98, 0x07 },
		{ 0xa8, 0x8d, 0xa2, 0x34 }
	};
	unsigned char ck [4][4] = {
    		kit.run(*pWindow);
  	}	

*/
//	Rijndael r(Rijndael::K128, Rijndael::B128);
//	timeval t1, t2;
/*	char input[1024];
	char ch[Rijndael::K128/8];
	unsigned char uch[Rijndael::K128/8];
	signed char sch[Rijndael::K128/8];*/
//	unsigned char a[5] = "abcd";
//	if (fgets(input, 16+1, stdin)){
//		if (sscanf(input, "%s", uch) == 1){
			//printf("%d\n", a[0]);
//		}
//	}
//	printf("%d\n", a);
//	gettimeofday(&t1, 0);
//	r.rotWord(a);
//	gettimeofday(&t2, 0);
/*	long mtime, seconds, useconds;
	seconds = t2.tv_sec - t1.tv_sec;
	useconds = t2.tv_usec - t1.tv_usec;
	mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	printf("%ld microseconds\n", mtime);
	printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);*/
//	printf("%d\n", _sbox[0]);
/*	unsigned char bk_round1 [4][4] = {
		{ 0x19, 0xa0, 0x9a, 0xe9 },
		{ 0x3d, 0xf4, 0xc6, 0xf8 },
		{ 0xe3, 0xe2, 0x8d, 0x48 },
		{ 0xbe, 0x2b, 0x2a, 0x08 }
	};
	unsigned char bk_round0 [4][4] = {
		{ 0x32, 0x88, 0x31, 0xe0 },
		{ 0x43, 0x5a, 0x31, 0x37 },
		{ 0xf6, 0x30, 0x98, 0x07 },
		{ 0xa8, 0x8d, 0xa2, 0x34 }
	};
	unsigned char ck [4][4] = {
		{ 0x2b, 0x7e, 0x15, 0x16 },
		{ 0x28, 0xae, 0xd2, 0xa6 },
		{ 0xab, 0xf7, 0x15, 0x88 },
		{ 0x09, 0xcf, 0x4f, 0x3c }
	};
	unsigned char bk [4][4] = {
		{ 0x00, 0x44, 0x88, 0xcc },
		{ 0x11, 0x55, 0x99, 0xdd },
		{ 0x22, 0x66, 0xaa, 0xee },
		{ 0x33, 0x77, 0xbb, 0xff }
	};
	unsigned char ck_1 [4][4] = {
		{ 0x00, 0x01, 0x02, 0x03 },
		{ 0x04, 0x05, 0x06, 0x07 },
		{ 0x08, 0x09, 0x0a, 0x0b },
		{ 0x0c, 0x0d, 0x0e, 0x0f }
	};
	unsigned char ck [6][4] = {
		{ 0x8e, 0x73, 0xb0, 0xf7 },
		{ 0xda, 0x0e, 0x64, 0x52 },
		{ 0xc8, 0x10, 0xf3, 0x2b },
		{ 0x80, 0x90, 0x79, 0xe5 },
		{ 0x62, 0xf8, 0xea, 0xd2 },
		{ 0x52, 0x2c, 0x6b, 0x7b }
	};*/

//	unsigned char ckoo[25] = "012345678901234567890123";
//	unsigned char bkoo[17] = "Texto para teste";
	// vector to block -> by column and by line
	// vector to key -> by line and by column
/*	unsigned char** ck1 = new unsigned char* [4];
//	unsigned char** bk1 = new unsigned char* [6];
	for (int i = 0; i < 4; i++){	
		ck1[i] = new unsigned char[4];	
		//bk1[i] = new unsigned char[4];
	}
*/		
/*	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			ck1[i][j] = ck[i][j];
//			bk1[i][j] = bk[i][j];
		}
	}*/

//	unsigned char ck192h[49] = "000102030405060708090a0b0c0d0e0f1011121314151617";
//	unsigned char ck256h[65] = "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f";
//	unsigned char ck256h[65] = "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4";
//	unsigned char ck192h[49] = "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b";
//	unsigned char ck192[25];
//	unsigned char ck256[33];
//	hexStringToCharString(ck256h, 64, ck256);
	//for (int i = 0; i < 24; i++)	printf("%x ", ck192[i]);
	//printf("\n");
//	unsigned char bk128h[33] = "00112233445566778899aabbccddeeff";
//	unsigned char bk128hc[33] = "8ea2b7ca516745bfeafc49904b496089";
//	unsigned char bk128[17];
//	hexStringToCharString(bk128h, 32, bk128);
//	gettimeofday(&t1, 0);
//	r.makeKey(&ck_demo[0][0]);
//	r.encrypt(bk128);
//	r.decrypt(bk128);
//	gettimeofday(&t2, 0);
//	for (int i = 0; i < 16; i++)	printf("%x ", bk128[i]);
//	printf("\n");

/*	gettimeofday(&t1, 0);
	r.makeKey(ckoo);	
	printf("%s\n", bkoo);
	r.encrypt(bkoo);
	printf("%s\n", bkoo);
	r.decrypt(bkoo);
	printf("%s\n", bkoo);*/
//	r.decrypt(bk1);*/
//	gettimeofday(&t2, 0);
	//printf("aqui\n");fflush(stdout);
	//printf("%s\n", ckoo);
//	printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
/*	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%x ", ck_1[i][j]);
		}
		printf("\n");
	}*/
/*	for (int i = 0; i < 4; i++){
//		delete[] bk1[i];
		delete[] ck1[i];
	}
//	delete[] bk1;
	delete[] ck1;*/
//	unsigned char a[1] = {0xbf};
/*	a[0] = a[0] << 1;		mult por 2
	a[0] ^= 0x1b;*/ 
	
//mult por 3
/*	a[0] = (a[0] << 1) ^ a[0];
	a[0] ^= 0x1b;*/
//	printf("%x\n", a[0]);
	return EXIT_SUCCESS;
}
