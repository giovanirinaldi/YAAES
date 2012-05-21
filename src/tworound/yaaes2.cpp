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

void copyMainDiagonalAndXorGuesses(unsigned char* k0, unsigned char** tempBlock_arrays, unsigned char** plaintexts, int num_texts){
	for (int i = 0; i < num_texts; i++){
		tempBlock_arrays[i][0] = plaintexts[i][0] ^ k0[0];
		tempBlock_arrays[i][5] = plaintexts[i][5] ^ k0[5];
		tempBlock_arrays[i][10] = plaintexts[i][10] ^ k0[10];
		tempBlock_arrays[i][15] = plaintexts[i][15] ^ k0[15];		
	}
}

void diff(unsigned char* block1, unsigned char* block2, unsigned char* dest){
	for (int i = 0; i < 16; i++){
		dest[i] = block1[i] ^ block2[i];
	}
}

unsigned char gfmult(unsigned char a, unsigned char b) {
        return mult_table[a][b];
}

unsigned char gfdiv(unsigned char a, unsigned char b) {
        return div_table[a][b];
}


void solveMixColumnFor2RoundPhase2(unsigned char * k2, unsigned char * u2){
        //both c0, c1 have 4 positions (each c is one column with 4 lines)
        //c0 is before, c1 is after mixcolumn
        //c0 and c1 will have usable values only at their 0 e 2 byes. 1 and 3 are the answer.
/*      unsigned char templeft = gfmult(k2[0][0], 0x03) ^ k2[2][0];
        unsigned char tempa = gfmult(u2[0][0], 0x06)  ^ u2[0][0];                       //gfmult(gfmult(c0[0], 0x02), 0x03);
        unsigned char tempc = gfmult(u2[2][0], 0x03) ^ gfmult(u2[2][0], 0x02);*/
//      unsigned char tempb = 0x04;             //0x01 ^ gfmult(0x03, 0x03);                    //fator da variavel b0 a ser resolvida
//      templeft ^= tempa ^ tempc;
//        u2[1] = gfdiv((gfmult(k2[0], 0x03) ^ k2[2]) ^ (gfmult(u2[0], 0x06)  ^ u2[0]) ^ (gfmult(u2[2], 0x03) ^ gfmult(u2[2], 0x02)), 0x04); //templeft, tempb
	printf("%.2x %.2x %.2x %.2x %.2x %.2x %.2x\n", mult_3_table[k2[0]], k2[2], u2[0], gfmult(u2[0], 0x06), mult_3_table[u2[2]], mult_2_table[u2[2]], u2[2]);
	printf("%.2x %.2x %.2x %.2x %.2x %.2x %.2x\n", gfmult(k2[0], 0x03), k2[2], u2[0], gfmult(u2[0], 0x06), mult_3_table[u2[2]], mult_2_table[u2[2]], u2[2]);
	u2[1] = gfdiv(mult_3_table[k2[0]] ^ k2[2] ^ gfmult(u2[0], 0x06)  ^ u2[0] ^ mult_3_table[u2[2]] ^ mult_2_table[u2[2]], 0x04); //templeft, tempb
        u2[3] = k2[0] ^ gfmult(u2[0], 0x02) ^ gfmult(u2[1], 0x03) ^ u2[2];
        k2[1] = u2[0] ^ gfmult(u2[1], 0x02) ^ gfmult(u2[2], 0x03) ^ u2[3];
        k2[3] = gfmult(u2[0], 0x03) ^ u2[1] ^ u2[2] ^ gfmult(u2[3], 0x02);
}

void findKeyForTwoRounds(FastRijndael* rijn, unsigned char** plaintexts, unsigned char** ciphertexts, int num_texts){
	unsigned char* invCipher1 = new unsigned char[16];
	unsigned char* invCipher2 = new unsigned char[16];
	unsigned char* invCipher3 = new unsigned char[16];
	unsigned char* invCipherDiff12 = new unsigned char[16];
	unsigned char* invCipherDiff13 = new unsigned char[16];
	unsigned char* plainDiff12 = new unsigned char[16];
	unsigned char* plainDiff13 = new unsigned char[16];
	unsigned char* cipherDiff12 = new unsigned char[16];
	unsigned char* cipherDiff13 = new unsigned char[16];

	diff(plaintexts[0], plaintexts[1], plainDiff12);
	diff(plaintexts[0], plaintexts[2], plainDiff13);
	diff(ciphertexts[0], ciphertexts[1], cipherDiff12);
	diff(ciphertexts[0], ciphertexts[2], cipherDiff13);
	
	diff(ciphertexts[0], ciphertexts[1], invCipherDiff12);
	diff(ciphertexts[0], ciphertexts[2], invCipherDiff13);
	rijn->invMixColumns(invCipherDiff12);
	rijn->invMixColumns(invCipherDiff13);
	rijn->invShiftRows(invCipherDiff12);
	rijn->invShiftRows(invCipherDiff13);
	
	copyBlock(ciphertexts[0], invCipher1);
	copyBlock(ciphertexts[1], invCipher2);
	copyBlock(ciphertexts[2], invCipher3);
	rijn->invMixColumns(invCipher1);
	rijn->invMixColumns(invCipher2);
	rijn->invMixColumns(invCipher3);
	
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

	unsigned char* k1_12_1 = new unsigned char[16];
	unsigned char* k1_12_2 = new unsigned char[1];
	unsigned char* k1_13_1 = new unsigned char[16];
	unsigned char* k1_13_2 = new unsigned char[16];
	
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
	register unsigned char poss_x;
	for (register short int m = 0; m < 1; m++){            //k0,0
                k0[0] = m;
                for (register short int n = 0; n < 6; n++){    //k0,5
                        k0[5] = n;
                        for (register short int o = 0; o < 11; o++){     //k0,10
                                k0[10] = o;
                                for (register short int p = 0; p < 16; p++){     //k0,15 
                                        k0[15] = p;
					
					copyMainDiagonalAndXorGuesses(k0, tempBlock_arrays, plaintexts, num_texts);
					for (fi = 0; fi < num_texts; fi++){
						rijn->subBytesMainDiagonal(tempBlock_arrays[fi]);
						rijn->shiftRowsMainDiagonal(tempBlock_arrays[fi]);
						rijn->mixOneColumn(tempBlock_arrays[fi], 0);
					}
					diff(tempBlock_arrays[0], tempBlock_arrays[1], tempBlockDiff12);
					diff(tempBlock_arrays[0], tempBlock_arrays[2], tempBlockDiff13);
	

					//aqui começa a comparar os pares p0,p1 e p0,p2 com os possiveis k1 de cada um	
				//	poss_x = x_sbox_diff[invCipherDiff12[0]*256 + tempBlockDiff12[0]];
					poss_x = x_sbox_diff[tempBlockDiff12[0]*256 + invCipherDiff12[0]];
				//	poss_x = y_sbox_diff[invCipherDiff12[0]*256 + tempBlockDiff12[0]];
				//	poss_x = y_sbox_diff[tempBlockDiff12[0]*256 + invCipherDiff12[0]];
					k1_12_1[0] = poss_x ^ tempBlock_arrays[0][0];
					k1_12_2[0] = poss_x ^ tempBlock_arrays[1][0];
					poss_x = x_sbox_diff[tempBlockDiff13[0]*256 + invCipherDiff13[0]];
					k1_13_1[0] = poss_x ^ tempBlock_arrays[0][0];
					k1_13_2[0] = poss_x ^ tempBlock_arrays[2][0];
					if (k1_12_1[0] == k1_13_1[0]|| k1_12_1[0] == k1_13_2[0] || k1_12_2[0] == k1_13_1[0] || k1_12_2[0] == k1_13_2[0]){
						if (k1_12_1[0] == k1_13_1[0]){
							k1[0] = k1_12_1[0];
						}
						if (k1_12_1[0] == k1_13_2[0]){
							k1[0] = k1_12_1[0];
						}
						if (k1_12_2[0] == k1_13_1[0]){
							k1[0] = k1_12_2[0];
						}
						if (k1_12_2[0] == k1_13_2[0]){
							k1[0] = k1_12_2[0];
						}
					}
					else{
						continue;
					}	

					
					poss_x = x_sbox_diff[tempBlockDiff12[1]*256 + invCipherDiff12[1]];
					k1_12_1[1] = poss_x ^ tempBlock_arrays[0][1];
					k1_12_2[1] = poss_x ^ tempBlock_arrays[1][1];
					poss_x = x_sbox_diff[tempBlockDiff13[1]*256 + invCipherDiff13[1]];
					k1_13_1[1] = poss_x ^ tempBlock_arrays[0][1];
					k1_13_2[1] = poss_x ^ tempBlock_arrays[2][1];
					if (k1_12_1[1] == k1_13_1[1]|| k1_12_1[1] == k1_13_2[1] || k1_12_2[1] == k1_13_1[1] || k1_12_2[1] == k1_13_2[1]){
						if (k1_12_1[1] == k1_13_1[1]){
							k1[1] = k1_12_1[1];
						}
						if (k1_12_1[1] == k1_13_2[1]){
							k1[1] = k1_12_1[1];
						}
						if (k1_12_2[1] == k1_13_1[1]){
							k1[1] = k1_12_2[1];
						}
						if (k1_12_2[1] == k1_13_2[1]){
							k1[1] = k1_12_2[1];
						}
					}
					else{
						continue;
					}
				
					poss_x = x_sbox_diff[tempBlockDiff12[2]*256 + invCipherDiff12[2]];
					k1_12_1[2] = poss_x ^ tempBlock_arrays[0][2];
					k1_12_2[2] = poss_x ^ tempBlock_arrays[1][2];
					poss_x = x_sbox_diff[tempBlockDiff13[2]*256 + invCipherDiff13[2]];
					k1_13_1[2] = poss_x ^ tempBlock_arrays[0][2];
					k1_13_2[2] = poss_x ^ tempBlock_arrays[2][2];
					if (k1_12_1[2] == k1_13_1[2]|| k1_12_1[2] == k1_13_2[2] || k1_12_2[2] == k1_13_1[2] || k1_12_2[2] == k1_13_2[2]){
						if (k1_12_1[2] == k1_13_1[2]){
							k1[2] = k1_12_1[2];
						}
						if (k1_12_1[2] == k1_13_2[2]){
							k1[2] = k1_12_1[2];
						}
						if (k1_12_2[2] == k1_13_1[2]){
							k1[2] = k1_12_2[2];
						}
						if (k1_12_2[2] == k1_13_2[2]){
							k1[2] = k1_12_2[2];
						}
					}
					else{
						continue;
					}

					poss_x = x_sbox_diff[tempBlockDiff12[3]*256 + invCipherDiff12[3]];
					k1_12_1[3] = poss_x ^ tempBlock_arrays[0][3];
					k1_12_2[3] = poss_x ^ tempBlock_arrays[1][3];
					poss_x = x_sbox_diff[tempBlockDiff13[3]*256 + invCipherDiff13[3]];
					k1_13_1[3] = poss_x ^ tempBlock_arrays[0][3];
					k1_13_2[3] = poss_x ^ tempBlock_arrays[2][3];
					if (k1_12_1[3] == k1_13_1[3]|| k1_12_1[3] == k1_13_2[3] || k1_12_2[3] == k1_13_1[3] || k1_12_2[3] == k1_13_2[3]){
						if (k1_12_1[3] == k1_13_1[3]){
							k1[3] = k1_12_1[3];
						}
						if (k1_12_1[3] == k1_13_2[3]){
							k1[3] = k1_12_1[3];
						}
						if (k1_12_2[3] == k1_13_1[3]){
							k1[3] = k1_12_2[3];
						}
						if (k1_12_2[3] == k1_13_2[3]){
							k1[3] = k1_12_2[3];
						}
					}
					else{
						continue;
					}
					//fim da procura pela primeira coluna de k1

					u2[0] = (_sbox[(tempBlock_arrays[0][0]^k1[0])] ^ invCipher1[0]);
					u2[13] = (_sbox[(tempBlock_arrays[0][1]^k1[1])] ^ invCipher1[13]);
					u2[10] = (_sbox[(tempBlock_arrays[0][2]^k1[2])] ^ invCipher1[10]);
					u2[7] = (_sbox[(tempBlock_arrays[0][3]^k1[3])] ^ invCipher1[7]);
				
					k0[2] = _sbox[k0[15]]^k1[2];
					k0[13] = _inv_sbox[k1[0]^0x01^k0[0]];
					k1[5] = k1[1]^k0[5];
				
					for (register int q = 0; q < 8; q++){
						k0[7] = q;
						for (register int r = 0; r < 9; r++){
							k0[8] = r;
						
							for (fi = 0; fi < 3; fi++){
								tempBlock_arrays[fi][9] = _sbox[plaintexts[fi][13] ^ k0[13]];
								tempBlock_arrays[fi][10] = _sbox[plaintexts[fi][2] ^ k0[2]];
								tempBlock_arrays[fi][8] = _sbox[plaintexts[fi][8] ^ r];
								tempBlock_arrays[fi][11] = _sbox[plaintexts[fi][7] ^ q];								
								rijn->mixOneColumn(tempBlock_arrays[fi], 2);
							}

							diff(tempBlock_arrays[0], tempBlock_arrays[1], tempBlockDiff12);
							diff(tempBlock_arrays[0], tempBlock_arrays[2], tempBlockDiff13);
						
							
							//aqui começa a comparar os pares p0,p1 e p0,p2 com os possiveis k1 de cada um	
							//	poss_x = x_sbox_diff[invCipherDiff12[0]*256 + tempBlockDiff12[0]];
							poss_x = x_sbox_diff[tempBlockDiff12[8]*256 + invCipherDiff12[8]];
							//	poss_x = y_sbox_diff[invCipherDiff12[0]*256 + tempBlockDiff12[0]];
							//	poss_x = y_sbox_diff[tempBlockDiff12[0]*256 + invCipherDiff12[0]];
							k1_12_1[8] = poss_x ^ tempBlock_arrays[0][8];
							k1_12_2[8] = poss_x ^ tempBlock_arrays[1][8];
							poss_x = x_sbox_diff[tempBlockDiff13[8]*256 + invCipherDiff13[8]];
							k1_13_1[8] = poss_x ^ tempBlock_arrays[0][8];
							k1_13_2[8] = poss_x ^ tempBlock_arrays[2][8];
							if (k1_12_1[8] == k1_13_1[8]|| k1_12_1[8] == k1_13_2[8] || k1_12_2[8] == k1_13_1[8] || k1_12_2[8] == k1_13_2[8]){
								if (k1_12_1[8] == k1_13_1[8]){
									k1[8] = k1_12_1[8];
								}
								if (k1_12_1[8] == k1_13_2[8]){
									k1[8] = k1_12_1[8];
								}
								if (k1_12_2[8] == k1_13_1[8]){
									k1[8] = k1_12_2[8];
								}
								if (k1_12_2[8] == k1_13_2[8]){
									k1[8] = k1_12_2[8];
								}
							}
							else{
								continue;
							}
	
							poss_x = x_sbox_diff[tempBlockDiff12[9]*256 + invCipherDiff12[9]];
							k1_12_1[9] = poss_x ^ tempBlock_arrays[0][9];
							k1_12_2[9] = poss_x ^ tempBlock_arrays[1][9];
							poss_x = x_sbox_diff[tempBlockDiff13[9]*256 + invCipherDiff13[9]];
							k1_13_1[9] = poss_x ^ tempBlock_arrays[0][9];
							k1_13_2[9] = poss_x ^ tempBlock_arrays[2][9];
							if (k1_12_1[9] == k1_13_1[9]|| k1_12_1[9] == k1_13_2[9] || k1_12_2[9] == k1_13_1[9] || k1_12_2[9] == k1_13_2[9]){
								if (k1_12_1[9] == k1_13_1[9]){
									k1[9] = k1_12_1[9];
								}
								if (k1_12_1[9] == k1_13_2[9]){
									k1[9] = k1_12_1[9];
								}
								if (k1_12_2[9] == k1_13_1[9]){
									k1[9] = k1_12_2[9];
								}
								if (k1_12_2[9] == k1_13_2[9]){
									k1[9] = k1_12_2[9];
								}
							}
							else{
								continue;
							}
				
							poss_x = x_sbox_diff[tempBlockDiff12[10]*256 + invCipherDiff12[10]];
							k1_12_1[10] = poss_x ^ tempBlock_arrays[0][10];
							k1_12_2[10] = poss_x ^ tempBlock_arrays[1][10];
							poss_x = x_sbox_diff[tempBlockDiff13[10]*256 + invCipherDiff13[10]];
							k1_13_1[10] = poss_x ^ tempBlock_arrays[0][10];
							k1_13_2[10] = poss_x ^ tempBlock_arrays[2][10];
							if (k1_12_1[10] == k1_13_1[10]|| k1_12_1[10] == k1_13_2[10] || k1_12_2[10] == k1_13_1[10] || k1_12_2[10] == k1_13_2[10]){
								if (k1_12_1[10] == k1_13_1[10]){
									k1[10] = k1_12_1[10];
								}
								if (k1_12_1[10] == k1_13_2[10]){
									k1[10] = k1_12_1[10];
								}
								if (k1_12_2[10] == k1_13_1[10]){
									k1[10] = k1_12_2[10];
								}
								if (k1_12_2[10] == k1_13_2[10]){
									k1[10] = k1_12_2[10];
								}
							}
							else{
								continue;
							}

							poss_x = x_sbox_diff[tempBlockDiff12[11]*256 + invCipherDiff12[11]];
							k1_12_1[11] = poss_x ^ tempBlock_arrays[0][11];
							k1_12_2[11] = poss_x ^ tempBlock_arrays[1][11];
							poss_x = x_sbox_diff[tempBlockDiff13[11]*256 + invCipherDiff13[11]];
							k1_13_1[11] = poss_x ^ tempBlock_arrays[0][11];
							k1_13_2[11] = poss_x ^ tempBlock_arrays[2][11];
							if (k1_12_1[11] == k1_13_1[11]|| k1_12_1[11] == k1_13_2[11] || k1_12_2[11] == k1_13_1[11] || k1_12_2[11] == k1_13_2[11]){
								if (k1_12_1[11] == k1_13_1[11]){
									k1[11] = k1_12_1[11];
								}
								if (k1_12_1[11] == k1_13_2[11]){
									k1[11] = k1_12_1[11];
								}
								if (k1_12_2[11] == k1_13_1[11]){
									k1[11] = k1_12_2[11];
								}
								if (k1_12_2[11] == k1_13_2[11]){
									k1[11] = k1_12_2[11];
								}
							}
							else{
								continue;
							}

							u2[8] = (_sbox[(tempBlock_arrays[0][8]^k1[8])] ^ invCipher1[8]);
							u2[5] = (_sbox[(tempBlock_arrays[0][9]^k1[9])] ^ invCipher1[5]);
							u2[2] = (_sbox[(tempBlock_arrays[0][10]^k1[10])] ^ invCipher1[2]);
							u2[15] = (_sbox[(tempBlock_arrays[0][11]^k1[11])] ^ invCipher1[15]);

							k1[7] = k1[3] ^ k0[7];
							k1[15] = k0[15] ^ k1[11];
							k1[13] = k0[13] ^ k1[9];
							k1[4] = k1[8] ^ k0[8];
							k1[6] = k1[10] ^ k0[10];

							k2[0] = (_sbox[k1[13]] ^ 0x02) ^ k1[0];
							k2[2] = (_sbox[k1[15]]) ^ k1[2];
				

/*							k1[12] = _inv_sbox[k2[3] ^ k1[3]];
							k1[14] = _inv_sbox[k2[1] ^ k1[1]];*/

							if (m == 0x00 && n == 0x05 && o == 0x0a && p == 0x0f && q == 0x07 && r == 0x08){
							solveMixColumnFor2RoundPhase2(k2, u2);
								printf("----------\n");
								printBlock(k0);
								printBlock(k1);
								printBlock(k2);
								printBlock(u2);
								printf("==============\n");
								//printf("%.2x %.2x %.2x %.2x\n", k1_12_1[0], k1_12_2[0], k1_13_1[0], k1_13_2[0]);*/
							}
						}
					}
					
				}
			}
		}
	}

	
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

	unsigned char chBlock1[33] = "00112233445566778899aabbccddeeff"; 
//	unsigned char chBlock1[33] = "00000000000000000000000000000000"; 	
        unsigned char* cBlock1_plain = new unsigned char [16];
        unsigned char* cBlock1_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock1, 32, cBlock1_plain);
	copyBlock(cBlock1_plain, cBlock1_cipher);
	rijn.encryptTwoRounds(cBlock1_cipher);

	unsigned char chBlock2[33] = "ffeeddccbbaa99887766554433221100"; 
//	unsigned char chBlock2[33] = "11111111111111111111111111111111"; 

        unsigned char* cBlock2_plain = new unsigned char [16];
        unsigned char* cBlock2_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock2, 32, cBlock2_plain);
	copyBlock(cBlock2_plain, cBlock2_cipher);
	rijn.encryptTwoRounds(cBlock2_cipher);
	
	unsigned char chBlock3[33] = "778899aabbccddeeff00112233445566"; 
        unsigned char* cBlock3_plain = new unsigned char [16];
        unsigned char* cBlock3_cipher = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock3, 32, cBlock3_plain);
	copyBlock(cBlock3_plain, cBlock3_cipher);
	rijn.encryptTwoRounds(cBlock3_cipher);

	/*printBlock(cBlock1_plain);	
	printBlock(cBlock1_cipher);	
	printBlock(cBlock2_plain);	
	printBlock(cBlock2_cipher);	
	printBlock(cBlock3_plain);	
	printBlock(cBlock3_cipher);	*/

	unsigned char** plaintexts_array = new unsigned char* [3];
	plaintexts_array[0] = cBlock1_plain;
	plaintexts_array[1] = cBlock2_plain;
	plaintexts_array[2] = cBlock3_plain;

	unsigned char** ciphertexts_array = new unsigned char* [3];
	ciphertexts_array[0] = cBlock1_cipher;
	ciphertexts_array[1] = cBlock2_cipher;
	ciphertexts_array[2] = cBlock3_cipher;
	
	findKeyForTwoRounds(&rijn, plaintexts_array, ciphertexts_array, 3);

	delete[] plaintexts_array,
	delete[] ciphertexts_array;

	delete[] cKey;
	delete[] cBlock1_plain;
	delete[] cBlock1_cipher;
	delete[] cBlock2_plain;
	delete[] cBlock2_cipher;
	delete[] cBlock3_plain;
	delete[] cBlock3_cipher;
	rijn.cleanUp();

	return 0;
}

