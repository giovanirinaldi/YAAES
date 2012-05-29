#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

using namespace std;

#include "rijndaelattacker.h"

#include "../fast-rijndael-1d/fast-rijndael-1d.h"
#include "../res/x_sbox_diff_coded.h"
#include "../res/y_sbox_diff_coded.h"
#include "../res/new_div_tables.h"
	
void RijndaelAttacker::copyBlock(unsigned char* block_src, unsigned char* block_dest){
	memcpy(block_dest, block_src, 16);
}

bool RijndaelAttacker::blocksAreEqual(unsigned char* block1, unsigned char* block2){
	for (int i = 0; i < 16; i++){
		if (block1[i] != block2[i]){
			return false;
		}
	}
	return true;
}

void RijndaelAttacker::copyMainDiagonalAndXorGuesses(unsigned char* k0, unsigned char** tempBlock_arrays, unsigned char** plaintexts, int num_texts){
	for (int i = 0; i < num_texts; i++){
		tempBlock_arrays[i][0] = plaintexts[i][0] ^ k0[0];
		tempBlock_arrays[i][1] = plaintexts[i][5] ^ k0[5];
		tempBlock_arrays[i][2] = plaintexts[i][10] ^ k0[10];
		tempBlock_arrays[i][3] = plaintexts[i][15] ^ k0[15];		
	}
}

void RijndaelAttacker::diff(unsigned char* block1, unsigned char* block2, unsigned char* dest){
	for (int i = 0; i < 16; i++){
		dest[i] = block1[i] ^ block2[i];
	}
}

void RijndaelAttacker::solveMixColumnFor2RoundPhase2(unsigned char * k2, unsigned char * u2){        
//        u2[1] = gfdiv((gfmult(k2[0], 0x03) ^ k2[2]) ^ (gfmult(u2[0], 0x06)  ^ u2[0]) ^ (gfmult(u2[2], 0x03) ^ gfmult(u2[2], 0x02)), 0x04); //templeft, tempb
	//printf("%.2x %.2x %.2x %.2x\n", k2[0], k2[2], u2[0], u2[2]);
	//printf("%.2x %.2x %.2x %.2x %.2x %.2x %.2x\n", mult_3_table[k2[0]], k2[2], u2[0], gfmult(u2[0], 0x06), mult_3_table[u2[2]], mult_2_table[u2[2]], u2[2]);
	//printf("%.2x %.2x %.2x %.2x %.2x %.2x %.2x\n", gfmult(k2[0], 0x03), k2[2], u2[0], gfmult(u2[0], 0x06), mult_3_table[u2[2]], mult_2_table[u2[2]], u2[2]);
	u2[1] = div_4_table[mult_3_table[k2[0]] ^ k2[2] ^ mult_6_table[u2[0]]  ^ u2[0] ^ mult_3_table[u2[2]] ^ mult_2_table[u2[2]]]; //templeft, tempb
        u2[3] = k2[0] ^ mult_2_table[u2[0]] ^ mult_3_table[u2[1]]^ u2[2];
        k2[1] = u2[0] ^ mult_2_table[u2[1]] ^ mult_3_table[u2[2]] ^ u2[3];
        k2[3] = mult_3_table[u2[0]]^ u2[1] ^ u2[2] ^ mult_2_table[u2[3]];
}

unsigned char RijndaelAttacker::xSboxDiff(unsigned char a, unsigned char b){
	return x_sbox_diff[a*256 + b];
}

unsigned char RijndaelAttacker::ySboxDiff(unsigned char a, unsigned char b){
	return y_sbox_diff[a*256 + b];
}

bool RijndaelAttacker::sboxDiffsMatches(unsigned char** tempBlock_arrays, unsigned char* tempBlockDiff12, unsigned char* tempBlockDiff13, unsigned char * invCipherDiff12, unsigned char* invCipherDiff13, unsigned char* k1, int from, int to){
	for (int i = from; i <= to; i++){
		//aqui começa a comparar os pares p0,p1 e p0,p2 com os possiveis k1 de cada um	
		//	poss_x = x_sbox_diff[invCipherDiff12[0]*256 + tempBlockDiff12[0]];
                poss_x = x_sbox_diff[tempBlockDiff12[i]*256 + invCipherDiff12[i]];
		//	poss_x = y_sbox_diff[invCipherDiff12[0]*256 + tempBlockDiff12[0]];
		//	poss_x = y_sbox_diff[tempBlockDiff12[0]*256 + invCipherDiff12[0]];
		k1_12_1[i] = poss_x ^ tempBlock_arrays[0][i];
		k1_12_2[i] = poss_x ^ tempBlock_arrays[1][i];
		poss_x = x_sbox_diff[tempBlockDiff13[i]*256 + invCipherDiff13[i]];
		k1_13_1[i] = poss_x ^ tempBlock_arrays[0][i];
		k1_13_2[i] = poss_x ^ tempBlock_arrays[2][i];
		if (k1_12_1[i] == k1_13_1[i]|| k1_12_1[i] == k1_13_2[i] || k1_12_2[i] == k1_13_1[i] || k1_12_2[i] == k1_13_2[i]){
			if (k1_12_1[i] == k1_13_1[i]){
				k1[i] = k1_12_1[i];
				continue;
			}
			if (k1_12_1[i] == k1_13_2[i]){
				k1[i] = k1_12_1[i];
				continue;
			}
			if (k1_12_2[i] == k1_13_1[i]){
				k1[i] = k1_12_2[i];
				continue;
			}
			if (k1_12_2[i] == k1_13_2[i]){
				k1[i] = k1_12_2[i];
				continue;
			}
		}
		else{
			return false;
		}
	}
	return true;
}

bool RijndaelAttacker::findKeyForTwoRounds(unsigned char** plaintexts, unsigned char** ciphertexts, int num_texts, unsigned char* k0found,
                                           short int k0b00from, short int k0b00to, short int k0b05from, short int k0b05to, short int k0b07from, short int k0b07to,
                                           short int k0b08from, short int k0b08to, short int k0b10from, short int k0b10to, short int k0b15from, short int k0b15to){
        FastRijndael rijn(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);

	unsigned char* invCipher1 = new unsigned char[16];
	unsigned char* invCipher2 = new unsigned char[16];
	unsigned char* invCipher3 = new unsigned char[16];
	unsigned char* invCipherDiff12 = new unsigned char[16];
	unsigned char* invCipherDiff13 = new unsigned char[16];
	unsigned char* plainDiff12 = new unsigned char[16];
	unsigned char* plainDiff13 = new unsigned char[16];
	unsigned char* cipherDiff12 = new unsigned char[16];
	unsigned char* cipherDiff13 = new unsigned char[16];
	unsigned char* testBlock = new unsigned char[16];

	diff(plaintexts[0], plaintexts[1], plainDiff12);
	diff(plaintexts[0], plaintexts[2], plainDiff13);
	diff(ciphertexts[0], ciphertexts[1], cipherDiff12);
	diff(ciphertexts[0], ciphertexts[2], cipherDiff13);
	
	diff(ciphertexts[0], ciphertexts[1], invCipherDiff12);
	diff(ciphertexts[0], ciphertexts[2], invCipherDiff13);
	rijn.invMixColumns(invCipherDiff12);
	rijn.invMixColumns(invCipherDiff13);
	rijn.invShiftRows(invCipherDiff12);
	rijn.invShiftRows(invCipherDiff13);
	
	copyBlock(ciphertexts[0], invCipher1);
	copyBlock(ciphertexts[1], invCipher2);
	copyBlock(ciphertexts[2], invCipher3);
	rijn.invMixColumns(invCipher1);
	rijn.invMixColumns(invCipher2);
	rijn.invMixColumns(invCipher3);
	
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
	unsigned long long countfour = 0;
	unsigned long long countafter1sbox = 0;
	unsigned long long countaftertestk0cipher2 = 0;
	unsigned long long countaftertestk0cipher3 = 0;
	unsigned long long countsix = 0;
	unsigned long long countafter2sbox = 0;
	unsigned long long countwrong = 0;
	unsigned long long countright = 0;

        for (register short int m = k0b00from; m <= k0b00to; m++){            //k0,0
                k0[0] = m;
                for (register short int n = k0b05from; n <= k0b05to; n++){    //k0,5
                        k0[5] = n;
                        for (register short int o = k0b10from; o <= k0b10to; o++){     //k0,10
                                k0[10] = o;
                                for (register short int p = k0b15from; p <= k0b15to; p++){     //k0,15
                                        k0[15] = p;
					countfour++;
                                        //printf("%.2x %.2x %.2x %.2x\n", m, n, o, p);
                                        //fflush(stdout);
					
					copyMainDiagonalAndXorGuesses(k0, tempBlock_arrays, plaintexts, num_texts);
					for (fi = 0; fi < num_texts; fi++){
/*						rijn->subBytesMainDiagonal(tempBlock_arrays[fi]);
						rijn->shiftRowsMainDiagonal(tempBlock_arrays[fi]);
						rijn->mixOneColumn(tempBlock_arrays[fi], 0);*/
						rijn.subBytesFirstColumn(tempBlock_arrays[fi]);
						//shift implicit
						rijn.mixFirstColumn(tempBlock_arrays[fi]);
					}
					diff(tempBlock_arrays[0], tempBlock_arrays[1], tempBlockDiff12);
					diff(tempBlock_arrays[0], tempBlock_arrays[2], tempBlockDiff13);
	

					if (!sboxDiffsMatches(tempBlock_arrays, tempBlockDiff12, tempBlockDiff13, invCipherDiff12, invCipherDiff13, k1, 0, 3)) continue;
					countafter1sbox++;
					//fim da procura pela primeira coluna de k1


					u2[0] = (_sbox[(tempBlock_arrays[0][0]^k1[0])] ^ invCipher1[0]);
					u2[13] = (_sbox[(tempBlock_arrays[0][1]^k1[1])] ^ invCipher1[13]);
					u2[10] = (_sbox[(tempBlock_arrays[0][2]^k1[2])] ^ invCipher1[10]);
					u2[7] = (_sbox[(tempBlock_arrays[0][3]^k1[3])] ^ invCipher1[7]);
	
					if ((_sbox[tempBlock_arrays[1][0] ^ k1[0]] ^ u2[0]) != invCipher2[0]){
						continue;
					}
					countaftertestk0cipher2++;
					if ((_sbox[tempBlock_arrays[2][0] ^ k1[0]] ^ u2[0]) != invCipher3[0]){
						continue;
					}
					countaftertestk0cipher3++;

					
					k0[2] = _sbox[k0[15]]^k1[2];
					k0[13] = _inv_sbox[k1[0]^0x01^k0[0]];
					k1[5] = k1[1]^k0[5];
				
                                        for (register int q = k0b07from; q <= k0b07to; q++){
						k0[7] = q;
                                                for (register int r = k0b08from; r <= k0b08to; r++){
							countsix++;
							k0[8] = r;
						
							for (fi = 0; fi < 3; fi++){
								tempBlock_arrays[fi][9] = _sbox[plaintexts[fi][13] ^ k0[13]];
								tempBlock_arrays[fi][10] = _sbox[plaintexts[fi][2] ^ k0[2]];
								tempBlock_arrays[fi][8] = _sbox[plaintexts[fi][8] ^ r];
								tempBlock_arrays[fi][11] = _sbox[plaintexts[fi][7] ^ q];								
								rijn.mixOneColumn(tempBlock_arrays[fi], 2);
							}

							diff(tempBlock_arrays[0], tempBlock_arrays[1], tempBlockDiff12);
							diff(tempBlock_arrays[0], tempBlock_arrays[2], tempBlockDiff13);
						
							
							if (!sboxDiffsMatches(tempBlock_arrays, tempBlockDiff12, tempBlockDiff13, invCipherDiff12, invCipherDiff13, k1, 8, 11)) continue;
							countafter2sbox++;

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
				
							solveMixColumnFor2RoundPhase2(k2, u2);

							k1[12] = _inv_sbox[k2[3] ^ k1[3]];
							k1[14] = _inv_sbox[k2[1] ^ k1[1]];

							//now we have k1 fully complete, let's get k0
							
							k0[12] = k1[8] ^ k1[12];
							k0[14] = k1[10] ^ k1[14];
							k0[9] = k1[5] ^ k1[9];
							k0[11] = k1[7] ^ k1[11];
							k0[4] = k1[0] ^ k1[4];
							k0[6] = k1[2] ^ k1[6];
							
							k0[1] = _sbox[k0[14]] ^ k1[1];
							k0[3] = _sbox[k0[12]] ^ k1[3];
							
							//k0 complete
//							count++;
							/*if (m == 0x0f && n == 0x05 && o == 0x0a && p == 0x0f && q == 0x07 && r == 0x08){
								printf("pass\n");
							}*/

							rijn.makeKey(k0);
							copyBlock(plaintexts[0], testBlock);
							rijn.encryptTwoRounds(testBlock);
							rijn.cleanUp();
							if (blocksAreEqual(ciphertexts[0], testBlock)){
								//printf("ok\n");
								//continue;
								copyBlock(k0, k0found);
								countright++;
								continue;
						/*		delete[] invCipher1;delete[] invCipher2;delete[] invCipher3;
								delete[] invCipherDiff12;delete[] invCipherDiff13;
								delete[] plainDiff12;delete[] plainDiff13;
								delete[] cipherDiff12;delete[] cipherDiff13;
								delete[] testBlock;	
								delete[] tempBlock1;delete[] tempBlock2;delete[] tempBlock3;	
								delete[] k0;delete[] k1;delete[] k2;delete[] u2;
								delete[] k1_12_1;delete[] k1_12_2;delete[] k1_13_1;delete[] k1_13_2;
								delete[] tempBlockDiff12;delete[] tempBlockDiff13;delete[] tempBlock_arrays;*/
								return true;			
							}
							else{
								countwrong++;
								continue;
							}
						}
					}
					
				}
			}
		}
	}

	printf("countfour %llu\n", countfour);
	printf("countsix %llu\n", countsix);
	printf("countaftertestk0cipher2 %llu\n", countaftertestk0cipher2);
	printf("countaftertestk0cipher3 %llu\n", countaftertestk0cipher3);
	printf("countafter1sbox %llu\n", countafter1sbox);
	printf("countafter2sbox %llu\n", countafter2sbox);
	printf("countwrong %llu\n", countwrong);
	printf("countright %llu\n", countright);

	delete[] invCipher1;delete[] invCipher2;delete[] invCipher3;
	delete[] invCipherDiff12;delete[] invCipherDiff13;
	delete[] plainDiff12;delete[] plainDiff13;
	delete[] cipherDiff12;delete[] cipherDiff13;
	delete[] testBlock;	
	delete[] tempBlock1;delete[] tempBlock2;delete[] tempBlock3;	
	delete[] k0;delete[] k1;delete[] k2;delete[] u2;
	delete[] k1_12_1;delete[] k1_12_2;delete[] k1_13_1;delete[] k1_13_2;
	delete[] tempBlockDiff12;delete[] tempBlockDiff13;delete[] tempBlock_arrays;

	return false;
}
