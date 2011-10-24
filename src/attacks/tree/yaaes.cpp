#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include <cstring>
#include <cctype>
//#include <gtkmm.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#include "fast-rijndael.h"
#include "../../res/x_sbox_diff_coded.h"
#include "../../res/y_sbox_diff_coded.h"

static unsigned char tempMixC0, tempMixC1, tempMixC2, tempMixC3;

static int count_ok, count_loops;
static int count_ok2, count_loops2;


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

void printBlock(unsigned char** block){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%.2x ", block[i][j]);
		}
		printf("\n");
	}
}

void findXYSboxDiff(ifstream * file, unsigned char alpha, unsigned char beta, unsigned char &x, unsigned char &y){
	// now this is bad.
	// given input/output diff of an Sbox, as alpha (in diff) and beta (out diff),
	// search the pre generated file for the possible input, which generated diff Alpha directly
	// and, diff beta by sbox[x]^sbox[y]. 
	char * bufferx = new char [2];
	char * buffery = new char [2];
//	ifstream file ("res/xy_sbox_diff_2");
	file->seekg(alpha*(256*5)+beta*5, ios::beg);
	file->read(bufferx, 2);
	file->read(buffery, 2);
	x = strtol(bufferx, NULL, 16);
	y = strtol(buffery, NULL, 16);
	delete bufferx;
	delete buffery;
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
	return div_table[a][b];
}


void solveMixColumnFor2RoundPhase2(unsigned char ** k2, unsigned char ** u2){
	//both c0, c1 have 4 positions (each c is one column with 4 lines)
	//c0 is before, c1 is after mixcolumn
	//c0 and c1 will have usable values only at their 0 e 2 byes. 1 and 3 are the answer.
/*	unsigned char templeft = gfmult(k2[0][0], 0x03) ^ k2[2][0];
	unsigned char tempa = gfmult(u2[0][0], 0x06)  ^ u2[0][0];			//gfmult(gfmult(c0[0], 0x02), 0x03);
	unsigned char tempc = gfmult(u2[2][0], 0x03) ^ gfmult(u2[2][0], 0x02);*/
//	unsigned char tempb = 0x04;		//0x01 ^ gfmult(0x03, 0x03);			//fator da variavel b0 a ser resolvida
//	templeft ^= tempa ^ tempc;
	u2[1][0] = gfdiv((gfmult(k2[0][0], 0x03) ^ k2[2][0]) ^ (gfmult(u2[0][0], 0x06)  ^ u2[0][0]) ^ (gfmult(u2[2][0], 0x03) ^ gfmult(u2[2][0], 0x02)), 0x04);	//templeft, tempb
	u2[3][0] = k2[0][0] ^ gfmult(u2[0][0], 0x02) ^ gfmult(u2[1][0], 0x03) ^ u2[2][0];
	k2[1][0] = u2[0][0] ^ gfmult(u2[1][0], 0x02) ^ gfmult(u2[2][0], 0x03) ^ u2[3][0];
	k2[3][0] = gfmult(u2[0][0], 0x03) ^ u2[1][0] ^ u2[2][0] ^ gfmult(u2[3][0], 0x02);
}
						
int compareAResultsWithB(unsigned char ** new_temp_b, unsigned char ** b_inv_cipher, unsigned char ** k0, unsigned char ** k1, unsigned char ** u2){
	new_temp_b[0][0] = _sbox[new_temp_b[0][0] ^ k0[0][0]];		
	new_temp_b[1][0] = _sbox[new_temp_b[1][1] ^ k0[1][1]];		
	new_temp_b[2][0] = _sbox[new_temp_b[2][2] ^ k0[2][2]];		
	new_temp_b[3][0] = _sbox[new_temp_b[3][3] ^ k0[3][3]];		
	tempMixC0 = new_temp_b[0][0];
	tempMixC1 = new_temp_b[1][0];
	tempMixC2 = new_temp_b[2][0];
	tempMixC3 = new_temp_b[3][0];
	new_temp_b[0][0] = gfmult(tempMixC0,0x02) ^ gfmult(tempMixC1,0x03) ^ tempMixC2 ^ tempMixC3;
	new_temp_b[1][0] = tempMixC0 ^ gfmult(tempMixC1,0x02) ^ gfmult(tempMixC2,0x3) ^ tempMixC3;
	new_temp_b[2][0] = tempMixC0 ^ tempMixC1 ^ gfmult(tempMixC2,0x02) ^ gfmult(tempMixC3,0x03);
	new_temp_b[3][0] = gfmult(tempMixC0,0x03) ^ tempMixC1 ^ tempMixC2 ^ gfmult(tempMixC3,0x02);
	new_temp_b[0][0] = _sbox[new_temp_b[0][0] ^ k1[0][0]] ^ u2[0][0];	
	new_temp_b[1][3] = _sbox[new_temp_b[1][0] ^ k1[1][0]] ^ u2[1][3];	
	new_temp_b[2][2] = _sbox[new_temp_b[2][0] ^ k1[2][0]] ^ u2[2][2];
	new_temp_b[3][1] = _sbox[new_temp_b[3][0] ^ k1[3][0]] ^ u2[3][1];
	count_loops++;
	if ( (new_temp_b[0][0] != b_inv_cipher[0][0]) ||
	     (new_temp_b[1][3] != b_inv_cipher[1][3]) ||
	     (new_temp_b[2][2] != b_inv_cipher[2][2]) ||
	     (new_temp_b[3][1] != b_inv_cipher[3][1])){
		return -1;
	}
//	printBlock(k0);
//	printf("\n");
//	sleep(5);
	count_ok++;
	return 0;
}

int compareAResultsWithBAgain(unsigned char ** new_temp_b, unsigned char ** b_inv_cipher, unsigned char ** k0, unsigned char ** k1, unsigned char ** u2){
	//this is ark/sb and shift altogether
	new_temp_b[0][2] = _sbox[new_temp_b[0][2] ^ k0[0][2]];		
	new_temp_b[1][2] = _sbox[new_temp_b[1][3] ^ k0[1][3]];		
	new_temp_b[2][2] = _sbox[new_temp_b[2][0] ^ k0[2][0]];		
	new_temp_b[3][2] = _sbox[new_temp_b[3][1] ^ k0[3][1]];		
	tempMixC0 = new_temp_b[0][2];
	tempMixC1 = new_temp_b[1][2];
	tempMixC2 = new_temp_b[2][2];
	tempMixC3 = new_temp_b[3][2];
	new_temp_b[0][2] = gfmult(tempMixC0,0x02) ^ gfmult(tempMixC1,0x03) ^ tempMixC2 ^ tempMixC3;
	new_temp_b[1][2] = tempMixC0 ^ gfmult(tempMixC1,0x02) ^ gfmult(tempMixC2,0x3) ^ tempMixC3;
	new_temp_b[2][2] = tempMixC0 ^ tempMixC1 ^ gfmult(tempMixC2,0x02) ^ gfmult(tempMixC3,0x03);
	new_temp_b[3][2] = gfmult(tempMixC0,0x03) ^ tempMixC1 ^ tempMixC2 ^ gfmult(tempMixC3,0x02);
	new_temp_b[0][2] = _sbox[new_temp_b[0][2] ^ k1[0][2]] ^ u2[0][2];	
	new_temp_b[1][1] = _sbox[new_temp_b[1][2] ^ k1[1][2]] ^ u2[1][1];	
	new_temp_b[2][0] = _sbox[new_temp_b[2][2] ^ k1[2][2]] ^ u2[2][0];
	new_temp_b[3][3] = _sbox[new_temp_b[3][2] ^ k1[3][2]] ^ u2[3][3];
	count_loops2++;
	if (new_temp_b[0][2] != b_inv_cipher[0][2])	return -1;
	if (new_temp_b[1][1] != b_inv_cipher[1][1])	return -1;
	if (new_temp_b[2][0] != b_inv_cipher[2][0])	return -1;
	if (new_temp_b[3][3] != b_inv_cipher[3][3])	return -1;
//	printBlock(k0);
//	printf("\n");
//	sleep(5);
	count_ok2++;
	return 0;
}
int main (int argc, char *argv[]){
/*	count_ok = 0;
	count_loops = 0;
	count_ok2 = 0;
	count_loops2 = 0;*/
/*	FastRijndael ri;	
	unsigned char** ttt = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		ttt[i] = new unsigned char[4];
	}
	ri.makeKey(ttt);
	for (long long int i = 0; i < 256*256*192; i++){	
		ri.encryptTwoRounds(ttt);	
	}
	printf("%x\n", ttt[3][3]);
	exit(0);*/
	/*ttt[0][0] = 0x41 ^ 0x0f; 
	ttt[1][1] = 0x32 ^ 0x0a; 
	ttt[2][2] = 0x49 ^ 0x05; 
	ttt[3][3] = 0x63 ^ 0x00; 
	ttt[0][0] = _sbox[ttt[0][0]]; 
	ttt[1][1] = _sbox[ttt[1][1]]; 
	ttt[2][2] = _sbox[ttt[2][2]]; 
	ttt[3][3] = _sbox[ttt[3][3]]; 
	ri.shiftRows(ttt);
	ri.mixOneColumn(ttt, 0);
	ttt[0][0] ^= 0xd9;
	ttt[1][0] ^= 0xaa;
	ttt[2][0] ^= 0x61;
	ttt[3][0] ^= 0xfd;
	ttt[0][0] = _sbox[ttt[0][0]]; 
	ttt[1][0] = _sbox[ttt[1][0]]; 
	ttt[2][0] = _sbox[ttt[2][0]]; 
	ttt[3][0] = _sbox[ttt[3][0]]; 
	ri.shiftRows(ttt);
	ttt[0][0] ^= 0x50;
	ttt[1][3] ^= 0xbc;
	ttt[2][2] ^= 0x98;
	ttt[3][1] ^= 0x81;
	printBlock(ttt);
	exit (0);*/
	//Rijndael r(Rijndael::K128, Rijndael::B128);
	//std::string key = "essasenhaehfraca";
	//std::string hBlock = "00112233445566778899aabbccddeeff";
	//546578746F2070617261207465737465";
	//char chBlock[65] = "00112233445566778899aabbccddeeff00112233445566778899aabbccddeeff";
//	char notABlock[] = "001122334455667788990a0b0c0d0e0f0011223344556677";
//	unsigned char cnotABlock[32];
	//hexStringToCharString((unsigned char*)notABlock, 20, cnotABlock);
	char chKey[33] = "0102030405060708090a0b0c0d0e0f";			//coluna 1 00010203 linha 1 0004080c
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
	unsigned char a_plain_char[17] = "0000000000000000"; 
	for (int i = 0; i < 4; i++){
		memcpy(a_plain[i], &a_plain_char[i*4], 4);
	}
	FastRijndael rijn(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);
	rijn.makeKey(cKey);	
	rijn.encryptTwoRounds(a_plain);	

	unsigned char** b_plain = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		b_plain[i] = new unsigned char[4];
	}
	unsigned char b_plain_char[17] = "1000100010001000"; 
	for (int i = 0; i < 4; i++){
		memcpy(b_plain[i], &b_plain_char[i*4], 4);
	}
	rijn.encryptTwoRounds(b_plain);	


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
	unsigned char** ab_inv_cipher_diff = new unsigned char* [4];
	unsigned char** a_inv_cipher = new unsigned char* [4];
	unsigned char** b_inv_cipher = new unsigned char* [4];
	unsigned char** ab_plain_diff = new unsigned char* [4];
	for (int i = 0; i < 4; i++){
		ab_cipher_diff[i] = new unsigned char[4];
		ab_inv_cipher_diff[i] = new unsigned char[4];
		a_inv_cipher[i] = new unsigned char[4];
		b_inv_cipher[i] = new unsigned char[4];
		ab_plain_diff[i] = new unsigned char[4];
		for (int j = 0; j < 4; j++){
			a_inv_cipher[i][j] = a_cipher[i][j];
			b_inv_cipher[i][j] = b_cipher[i][j];
		}
	}
	diff(a_plain, b_plain, ab_plain_diff);
	diff(a_cipher, b_cipher, ab_cipher_diff);
	diff(a_cipher, b_cipher, ab_inv_cipher_diff);

	rijn.subBytes(ab_plain_diff);
	rijn.shiftRows(ab_plain_diff);
	rijn.mixColumns(ab_plain_diff);

	printf("--------------\n");
	printf("AB Plain diff\n");
	printBlock(ab_plain_diff);
	printf("AB Cipher diff\n");
	printBlock(ab_cipher_diff);	
	printf("--------------\n");

	rijn.invMixColumns(ab_inv_cipher_diff);
	rijn.invShiftRows(ab_inv_cipher_diff);

	printf("--------------\n");
	printf("AB Cipher diff after invMC and invSR\n");
	printBlock(ab_inv_cipher_diff);	
	printf("--------------\n");

	for (int i = 0; i < 256; i ++){
		printf("%.2x %.2x %.2x %.2x\n", ab_plain_diff[0][0]^i, ab_plain_diff[1][0]^i, ab_plain_diff[2][0]^i, ab_plain_diff[3][0]^i);
	}

	exit(0);

	//256^4 possibilities for diagonal at k0, 0,5,10,15 
	unsigned char*** k1_pos = new unsigned char**[4];
	unsigned char** k0 = new unsigned char*[4];
	unsigned char** k1 = new unsigned char*[4];
	unsigned char** k2 = new unsigned char*[4];
	unsigned char** u2 = new unsigned char*[4];
	unsigned char** temp_a = new unsigned char*[4];
	unsigned char** temp_b = new unsigned char*[4];
	unsigned char** diff_temp_ab = new unsigned char*[4];
	for (int i = 0; i < 4; i++){
		k1_pos[i] = new unsigned char*[4];
		for (int j = 0; j < 4; j++){
			k1_pos[i][j] = new unsigned char[2];
		}
		k0[i] = new unsigned char[4];
		k1[i] = new unsigned char[4];
		k2[i] = new unsigned char[4];
		u2[i] = new unsigned char[4];
		temp_a[i] = new unsigned char[4];
		temp_b[i] = new unsigned char[4];
		diff_temp_ab[i] = new unsigned char[4];
	}	
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 2; k++){
				k1_pos[i][j][k] = 0x00;
			}
			k0[i][j] = 0x00;
			k1[i][j] = 0x00;
			k2[i][j] = 0x00;
			u2[i][j] = 0x00;
			temp_a[i][j] = 0x00;
			temp_b[i][j] = 0x00;
		}
	}
	//now i'll pretend to calculate that, and found it!, for block A. its 00, 05, 0a, 0f!
	//k0[0][0] = 0x00;
	//k0[1][1] = 0x05;
	//k0[2][2] = 0x0a;
	//k0[3][3] = 0x0f;
	
	unsigned char** new_temp_a = new unsigned char*[4];
	unsigned char** new_temp_b = new unsigned char*[4];
	for (int i = 0; i < 4; i++){	
		new_temp_a[i] = new unsigned char[4];
		new_temp_b[i] = new unsigned char[4];
	}
	register unsigned char poss_x;
	//guess 4 bytes at k0
	for (register short int m = 0; m < 16; m++){		//k0,0
		k0[0][0] = m;
		for (register short int n = 0; n < 11; n++){	//k0,5
			k0[1][1] = n;
			for (register short int o = 0; o < 6; o++){	//k0,10
				k0[2][2] = o;
				for (register short int p = 0; p < 1; p++){	//k0,15	
					k0[3][3] = p;
//					printf("%.2x %.2x %.2x %.2x\n", m, n, o, p);
					//get them just before ARK at first round
					temp_a[0][0] = a_plain[0][0] ^ m;
					temp_b[0][0] = b_plain[0][0] ^ m;		
					temp_a[1][1] = a_plain[1][1] ^ n;
					temp_b[1][1] = b_plain[1][1] ^ n;		
					temp_a[2][2] = a_plain[2][2] ^ o;
					temp_b[2][2] = b_plain[2][2] ^ o;		
					temp_a[3][3] = a_plain[3][3] ^ p;
					temp_b[3][3] = b_plain[3][3] ^ p;		
					rijn.subBytesMainDiagonal(temp_a);
					rijn.subBytesMainDiagonal(temp_b);
					rijn.shiftRowsMainDiagonal(temp_a);
					rijn.shiftRowsMainDiagonal(temp_b);
					rijn.mixOneColumn(temp_a, 0);
					rijn.mixOneColumn(temp_b, 0);
					//compare with output diff after SB at second round
					diff(temp_a, temp_b, diff_temp_ab, 0, 3, 0, 0);
					for (int i = 0; i < 4; i++){
						poss_x = x_sbox_diff[diff_temp_ab[i][0]*256 + ab_inv_cipher_diff[i][0]]; 
						k1_pos[i][0][0] = poss_x^temp_a[i][0];
						k1_pos[i][0][1] = poss_x^temp_b[i][0];
					}
					for (int k100 = 0; k100 < 2; k100++){
				         k1[0][0] = k1_pos[0][0][k100];
					 for (int k110 = 0; k110 < 2; k110++){
					  k1[1][0] = k1_pos[1][0][k110];
					  for (int k120 = 0; k120 < 2; k120++){
					   k1[2][0] = k1_pos[2][0][k120];
					   for (int k130 = 0; k130 < 2; k130++){
					    k1[3][0] = k1_pos[3][0][k130];
						//check 16 combinations that make input/output diff
						u2[0][0] = (_sbox[(temp_a[0][0]^k1[0][0])]^a_inv_cipher[0][0]);
						u2[1][3] = (_sbox[(temp_a[1][0]^k1[1][0])]^a_inv_cipher[1][3]);
						u2[2][2] = (_sbox[(temp_a[2][0]^k1[2][0])]^a_inv_cipher[2][2]);
						u2[3][1] = (_sbox[(temp_a[3][0]^k1[3][0])]^a_inv_cipher[3][1]);
						for (int i = 0; i < 4; i++){
							new_temp_b[i][i] = b_plain[i][i];
						}
						if (compareAResultsWithB(new_temp_b, b_inv_cipher, k0, k1, u2) == -1)	continue;
						//key schedule exploit
						k0[2][0] = _sbox[k0[3][3]]^k1[2][0];
						k0[1][3] = _inv_sbox[k1[0][0]^0x01^k0[0][0]];
						k1[1][1] = k1[1][0]^k0[1][1];
					/*	if (m == 0x0f && n == 0x0a && o == 0x05 && p == 0x00 && k1[0][0] == 0xd9 && k1[1][0] == 0xaa && k1[2][0] == 0x61 && k1[3][0] == 0xfd){
							printBlock(k0);
						}*/
						//here begins phase 2
						//calculate new k0 over a and b
//						temp_a[1][2] = _sbox[a_plain[1][3] ^ k0[1][3]];								
//						temp_b[1][2] = _sbox[b_plain[1][3] ^ k0[1][3]];								
//						temp_a[2][2] = _sbox[a_plain[2][0] ^ k0[2][0]];								
//						temp_b[2][2] = _sbox[b_plain[2][0] ^ k0[2][0]];								
						//if (m == 0x00 && n == 0x05 && o == 0x0a && p == 0x0f && k1[0][0] == 0xd6 && k1[1][0] == 0xaa && k1[2][0] == 0x74 && k1[3][0] == 0xfd){
						//	printf("%x %x %x\n", temp_a[1][2], a_plain[1][3], k0[1][3]);
						//}
						//guess new bytes k0,7 and k0,8
						for (int q = 0; q < 8; q++){	//this would be k0,7
							for (int r = 0; r < 9; r++){	//and this k0,8
								k0[3][1] = q;	k0[0][2] = r;
						/*		if (m == 0x0f && n == 0x0a && o == 0x05 && p == 0x00 && k1[0][0] == 0xd9 && k1[1][0] == 0xaa && k1[2][0] == 0x61 && k1[3][0] == 0xfd && q == 0x07 && r == 0x08){
									printBlock(k0);
									printBlock(k1);
								}*/
								//this is repeated up there, because of mixcolumns
								temp_a[1][2] = _sbox[a_plain[1][3] ^ k0[1][3]];								
								temp_b[1][2] = _sbox[b_plain[1][3] ^ k0[1][3]];								
								temp_a[2][2] = _sbox[a_plain[2][0] ^ k0[2][0]];								
								temp_b[2][2] = _sbox[b_plain[2][0] ^ k0[2][0]];								
								temp_a[0][2] = _sbox[a_plain[0][2] ^ r];								
								temp_b[0][2] = _sbox[b_plain[0][2] ^ r];								
								temp_a[3][2] = _sbox[a_plain[3][1] ^ q];								
								temp_b[3][2] = _sbox[b_plain[3][1] ^ q];		
								rijn.mixOneColumn(temp_a, 2);
								rijn.mixOneColumn(temp_b, 2);
								//compare inout diff at sb/ark1
								diff(temp_a, temp_b, diff_temp_ab, 0, 3, 2, 2);
								for (int i = 0; i < 4; i++){
									poss_x = x_sbox_diff[diff_temp_ab[i][2]*256 + ab_inv_cipher_diff[i][2]]; 
									k1_pos[i][2][0] = poss_x^temp_a[i][2];
									k1_pos[i][2][1] = poss_x^temp_b[i][2];
								}								
								for (int k102 = 0; k102 < 2; k102++){
 								 k1[0][2] = k1_pos[0][2][k102];
								 for (int k112 = 0; k112 < 2; k112++){
								  k1[1][2] = k1_pos[1][2][k112];
								  for (int k122 = 0; k122 < 2; k122++){
								   k1[2][2] = k1_pos[2][2][k122];
								   for (int k132 = 0; k132 < 2; k132++){
								    k1[3][2] = k1_pos[3][2][k132];
									//check 16 combinations that make input/output diff
									u2[0][2] = (_sbox[temp_a[0][2] ^ k1[0][2]]) ^ a_inv_cipher[0][2];
									u2[1][1] = (_sbox[temp_a[1][2] ^ k1[1][2]]) ^ a_inv_cipher[1][1];
									u2[2][0] = (_sbox[temp_a[2][2] ^ k1[2][2]]) ^ a_inv_cipher[2][0];
									u2[3][3] = (_sbox[temp_a[3][2] ^ k1[3][2]]) ^ a_inv_cipher[3][3];
									new_temp_b[0][2] = b_plain[0][2];
									new_temp_b[1][3] = b_plain[1][3];
									new_temp_b[2][0] = b_plain[2][0];
									new_temp_b[3][1] = b_plain[3][1];							
									if (compareAResultsWithBAgain(new_temp_b, b_inv_cipher, k0, k1, u2) == -1)	continue;
									//step 9 and 10, key sched exploit
									k1[3][1] = k1[3][0] ^ k0[3][1];
									k1[3][3] = k0[3][3] ^ k1[3][2];
									k1[1][3] = k0[1][3] ^ k1[1][2];
									k1[0][1] = k1[0][2] ^ k0[0][2];
									k1[2][1] = k1[2][2] ^ k0[2][2];
									//step 11
									k2[0][0] = (_sbox[k1[1][3]] ^ 0x02) ^ k1[0][0];
									k2[2][0] = (_sbox[k1[3][3]]) ^ k1[2][0];
									solveMixColumnFor2RoundPhase2(k2, u2);
									k1[0][3] = _inv_sbox[k2[3][0] ^ k1[3][0]];
									k1[2][3] = _inv_sbox[k2[1][0] ^ k1[1][0]];
									if (m == 0x0f && n == 0x0a && o == 0x05 && p == 0x00 && k1[0][0] == 0xd9 && k1[1][0] == 0xaa && k1[2][0] == 0x61 && k1[3][0] == 0xfd && q == 0x07 && r == 0x08 &&
									    k1[0][2] == 0xd5 && k1[1][2] == 0xa9 && k1[2][2] == 0x62 && k1[3][2] ==0xf1){
										printf("k0\n");printBlock(k0);
										printf("k1\n");printBlock(k1);
										printf("u2\n");printBlock(u2);
										printf("k2\n");printBlock(k2);				
									}
								}}}}
							}
						}
					}}}}
				}
			}
		}
	}

	printf("%d %d\n", count_loops, count_ok);	
	printf("%d %d\n", count_loops2, count_ok2);	

//Generate xy sbox diff
/*	FILE * file;
	file = fopen("xy_sbox_diff_coded", "w");

	unsigned char*** xy_sbox = new unsigned char**[256];
	for (int i = 0; i < 256; i++){
		xy_sbox[i] = new unsigned char*[256];
		for (int j = 0; j < 256; j++){
			xy_sbox[i][j] = new unsigned char[2];
			xy_sbox[i][j][0] = 0x00;
			xy_sbox[i][j][1] = 0x00;		
		}
	}
	unsigned char a = 0x00;
	unsigned char b = 0x00;
	for (int i = 0; i < 256; i++){
		for (int j = 0; j < 256; j++){
			for (unsigned char x = 0x00; x <= 0xff; x=x+0x01){
				for (unsigned char y = 0x00; y <= 0xff; y=y+0x01){
					if (((x^y) == a) && ((_sbox[x]^_sbox[y]) == b)){
						xy_sbox[i][j][0] = x;
						xy_sbox[i][j][1] = y;
						break;
					}
					if (y == 0xff)	break;
				}
				if (x == 0xff)	break;
			}
			b++;
		}
		a++;
	}
	
	for (int i = 0; i < 256; i++){
		for (int j = 0; j < 256; j++){
			fprintf(file, "0x%.2x,", xy_sbox[i][j][1]);
		}
	}
	fclose(file);*/
	//alloc possibilities matrix. for each position (16 pos total), 2 posibilities of 1 byte key
/*	unsigned char*** pos = new unsigned char**[4];
	unsigned char*** k0 = new unsigned char**[4];
	unsigned char*** k1 = new unsigned char**[4];

	unsigned char** final_k0 = new unsigned char*[4];
	unsigned char** final_k1 = new unsigned char*[4];

	for (int i = 0; i < 4; i++){
		pos[i] = new unsigned char*[4];
		k0[i] = new unsigned char*[4];
		k1[i] = new unsigned char*[4];
		final_k0[i] = new unsigned char[4];
		final_k1[i] = new unsigned char[4];
		for (int j = 0; j < 4; j++){
			pos[i][j] = new unsigned char[2];
			k0[i][j] = new unsigned char[2];
			k1[i][j] = new unsigned char[2];
		}
	}	
	unsigned char a, b;
	int count = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			a = ab_plain_diff[i][j];
			b = ab_inv_cipher_diff[i][j];
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

	unsigned char*** temp_k0 = new unsigned char**[16];
	for (int i = 0; i < 16; i++){
		temp_k0[i] = new unsigned char*[4];
		for (int j = 0; j < 4; j++){
			temp_k0[i][j] = new unsigned char[4];
		}
	}	
	unsigned char** temp_k1c0 = new unsigned char*[16];
	unsigned char** temp_k1c1 = new unsigned char*[16];
	unsigned char** temp_k1c2 = new unsigned char*[16];
	unsigned char** temp_k1c3 = new unsigned char*[16];
	for (int i = 0; i < 16; i++){
		temp_k1c0[i] = new unsigned char[4];
		temp_k1c1[i] = new unsigned char[4];		
		temp_k1c2[i] = new unsigned char[4];		
		temp_k1c3[i] = new unsigned char[4];		
	}
	
	for (int i = 0; i < 16; i++){
		if (i & 1){
			temp_k1c0[i][0] = _sbox[pos[0][0][0]];
			temp_k0[i][0][0] = pos[0][0][0];
		}
		else{
			temp_k1c0[i][0] = _sbox[pos[0][0][1]];
			temp_k0[i][0][0] = pos[0][0][1];
		}
		if (i & 2){
			temp_k1c0[i][1] = _sbox[pos[1][1][0]];
			temp_k0[i][1][1] = pos[1][1][0];
		}
		else{
			temp_k1c0[i][1] = _sbox[pos[1][1][1]];
			temp_k0[i][1][1] = pos[1][1][1];
		}
		if (i & 4){
			temp_k1c0[i][2] = _sbox[pos[2][2][0]];
			temp_k0[i][2][2] = pos[2][2][0];
		}
		else{
			temp_k1c0[i][2] = _sbox[pos[2][2][1]];
			temp_k0[i][2][2] = pos[2][2][1];
		}
		if (i & 8){
			temp_k1c0[i][3] = _sbox[pos[3][3][0]];
			temp_k0[i][3][3] = pos[3][3][0];
		}
		else{
			temp_k1c0[i][3] = _sbox[pos[3][3][1]];
			temp_k0[i][3][3] = pos[3][3][1];
		}
	}

	for (int i = 0; i < 16; i++){
		if (i & 1){	//i'm fucking stupid. line order in tempk1c* must go with line order from pos[][]
			temp_k1c1[i][3] = _sbox[pos[3][0][0]];
			temp_k0[i][3][0] = pos[3][0][0];
		}
		else{
			temp_k1c1[i][3] = _sbox[pos[3][0][1]];
			temp_k0[i][3][0] = pos[3][0][1];
		}
		if (i & 2){
			temp_k1c1[i][0] = _sbox[pos[0][1][0]];
			temp_k0[i][0][1] = pos[0][1][0];
		}
		else{
			temp_k1c1[i][0] = _sbox[pos[0][1][1]];
			temp_k0[i][0][1] = pos[0][1][1];
		}
		if (i & 4){
			temp_k1c1[i][1] = _sbox[pos[1][2][0]];
			temp_k0[i][1][2] = pos[1][2][0];
		}
		else{
			temp_k1c1[i][1] = _sbox[pos[1][2][1]];
			temp_k0[i][1][2] = pos[1][2][1];
		}
		if (i & 8){
			temp_k1c1[i][2] = _sbox[pos[2][3][0]];
			temp_k0[i][2][3] = pos[2][3][0];
		}
		else{
			temp_k1c1[i][2] = _sbox[pos[2][3][1]];
			temp_k0[i][2][3] = pos[2][3][1];
		}
	}
	
	for (int i = 0; i < 16; i++){
		if (i & 1){
			temp_k1c2[i][0] = _sbox[pos[0][2][0]];
			temp_k0[i][0][2] = pos[0][2][0];
		}
		else{
			temp_k1c2[i][0] = _sbox[pos[0][2][1]];
			temp_k0[i][0][2] = pos[0][2][1];
		}
		if (i & 2){
			temp_k1c2[i][1] = _sbox[pos[1][3][0]];
			temp_k0[i][1][3] = pos[1][3][0];
		}
		else{
			temp_k1c2[i][1] = _sbox[pos[1][3][1]];
			temp_k0[i][1][3] = pos[1][3][1];
		}
		if (i & 4){
			temp_k1c2[i][2] = _sbox[pos[2][0][0]];
			temp_k0[i][2][0] = pos[2][0][0];
		}
		else{
			temp_k1c2[i][2] = _sbox[pos[2][0][1]];
			temp_k0[i][2][0] = pos[2][0][1];
		}
		if (i & 8){
			temp_k1c2[i][3] = _sbox[pos[3][1][0]];
			temp_k0[i][3][1] = pos[3][1][0];
		}
		else{
			temp_k1c2[i][3] = _sbox[pos[3][1][1]];
			temp_k0[i][3][1] = pos[3][1][1];
		}
	}

	for (int i = 0; i < 16; i++){
		if (i & 1){
			temp_k1c3[i][0] = _sbox[pos[0][3][0]];
			temp_k0[i][0][3] = pos[0][3][0];
		}
		else{
			temp_k1c3[i][0] = _sbox[pos[0][3][1]];
			temp_k0[i][0][3] = pos[0][3][1];
		}
		if (i & 2){
			temp_k1c3[i][1] = _sbox[pos[1][0][0]];
			temp_k0[i][1][0] = pos[1][0][0];
		}
		else{
			temp_k1c3[i][1] = _sbox[pos[1][0][1]];
			temp_k0[i][1][0] = pos[1][0][1];
		}
		if (i & 4){
			temp_k1c3[i][2] = _sbox[pos[2][1][0]];
			temp_k0[i][2][1] = pos[2][1][0];
		}
		else{
			temp_k1c3[i][2] = _sbox[pos[2][1][1]];
			temp_k0[i][2][1] = pos[2][1][1];
		}
		if (i & 8){
			temp_k1c3[i][3] = _sbox[pos[3][2][0]];
			temp_k0[i][3][2] = pos[3][2][0];
		}
		else{
			temp_k1c3[i][3] = _sbox[pos[3][2][1]];
			temp_k0[i][3][2] = pos[3][2][1];
		}
	}

	unsigned char** temp_k1 = new unsigned char*[4];
	for (int i = 0; i < 4; i++){
		temp_k1[i] = new unsigned char[4];
	}	
	for (int i = 0; i < 16; i++){
		for (int m = 0; m < 4; m++){
			for (int n = 0; n < 4; n++){
				temp_k0[i][m][n] = (temp_k0[i][m][n]^a_plain[m][n]);					
			}
		}
	}
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			temp_k1[0][0] = temp_k1c0[i][0];
			temp_k1[1][0] = temp_k1c0[i][1];
			temp_k1[2][0] = temp_k1c0[i][2];
			temp_k1[3][0] = temp_k1c0[i][3];
			temp_k1[0][1] = temp_k1c1[j][0];
			temp_k1[1][1] = temp_k1c1[j][1];
			temp_k1[2][1] = temp_k1c1[j][2];
			temp_k1[3][1] = temp_k1c1[j][3];
			r.mixColumns(temp_k1);
			for (int m = 0; m < 4; m++){
				for (int n = 0; n < 2; n++){
					temp_k1[m][n] = temp_k1[m][n]^a_cipher[m][n];
				}
			}
			if (	(temp_k1[0][1] == (temp_k0[j][0][1] ^ temp_k1[0][0])) &&
				(temp_k1[1][1] == (temp_k0[i][1][1] ^ temp_k1[1][0]))){ 
				for (int m = 0; m < 4; m++){
					for (int n = 0; n < 2; n++){
						final_k1[m][n] = temp_k1[m][n];
					}
				}
				final_k0[0][0] = temp_k0[i][0][0]; final_k0[0][1] = temp_k0[j][0][1];
				final_k0[1][1] = temp_k0[i][1][1]; final_k0[1][2] = temp_k0[j][1][2];
				final_k0[2][2] = temp_k0[i][2][2]; final_k0[2][3] = temp_k0[j][2][3];
				final_k0[3][3] = temp_k0[i][3][3]; final_k0[3][0] = temp_k0[j][3][0];				
			}
		}
	}
	
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			temp_k1[0][2] = temp_k1c2[i][0];
			temp_k1[1][2] = temp_k1c2[i][1];
			temp_k1[2][2] = temp_k1c2[i][2];
			temp_k1[3][2] = temp_k1c2[i][3];
			temp_k1[0][3] = temp_k1c3[j][0];
			temp_k1[1][3] = temp_k1c3[j][1];
			temp_k1[2][3] = temp_k1c3[j][2];
			temp_k1[3][3] = temp_k1c3[j][3];
			r.mixColumns(temp_k1);
			for (int m = 0; m < 4; m++){
				for (int n = 2; n < 4; n++){
					temp_k1[m][n] = temp_k1[m][n]^a_cipher[m][n];
				}
			}
			if (	(temp_k1[0][3] == (temp_k0[j][0][3] ^ temp_k1[0][2])) && 
				(temp_k1[1][3] == (temp_k0[i][1][3] ^ temp_k1[1][2]))){ 
				for (int m = 0; m < 4; m++){
					for (int n = 2; n < 4; n++){
						final_k1[m][n] = temp_k1[m][n];
					}
				}
				final_k0[0][2] = temp_k0[i][0][2]; final_k0[0][3] = temp_k0[j][0][3];
				final_k0[1][3] = temp_k0[i][1][3]; final_k0[1][0] = temp_k0[j][1][0];
				final_k0[2][0] = temp_k0[i][2][0]; final_k0[2][1] = temp_k0[j][2][1];
				final_k0[3][1] = temp_k0[i][3][1]; final_k0[3][2] = temp_k0[j][3][2];
			}
		}
	}
	
	printf("K0 is\n");	
	for (int m = 0; m < 4; m++){
		for (int n = 0; n < 4; n++){
			printf("%.2x ", final_k0[m][n]);
		}
		printf("\n");
	}
	printf("\n");
	printf("K1 is\n");	
	for (int m = 0; m < 4; m++){
		for (int n = 0; n < 4; n++){
			printf("%.2x ", final_k1[m][n]);
		}
		printf("\n");
	}
	
*/

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
