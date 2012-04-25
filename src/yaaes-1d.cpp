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
#include <string>
#include <iostream>
#include <fstream>
#include <bitset>

#include <sys/types.h>
#include <dirent.h>

using namespace std;

#include "fast-rijndael-1d/fast-rijndael-1d.h"

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

	/*struct dirent *de = NULL;
	DIR *d = NULL;

	d = opendir("./kat/");
	
	FastRijndael rijn_kat;
	FastRijndael::Mode mode = FastRijndael::ECB;
	FastRijndael::KeySize ks = FastRijndael::K128;

	unsigned char* chKey128 = new unsigned char [32];
	unsigned char* cKey128 = new unsigned char [16];
	unsigned char* chKey192 = new unsigned char [48];
	unsigned char* cKey192 = new unsigned char [24];
	unsigned char* chKey256 = new unsigned char [64];
	unsigned char* cKey256 = new unsigned char [32];
	unsigned char* chIV = new unsigned char [32];
	unsigned char* cIV = new unsigned char [16];

	unsigned char* chKey = chKey128;
        unsigned char* cKey = cKey128;
	unsigned char* chBlock = new unsigned char [32];
        unsigned char* cBlock = new unsigned char [16];
	unsigned char* chAnsw = new unsigned char [32];
        unsigned char* cAnsw = new unsigned char [16];
	int key_hexchar_size = 32;
	int blockLen = 16;
	bool encrypt = true;
	string count = "";

	std::string file;
	while (de = readdir(d)){		
		file = std::string(de->d_name);
		if (file.find(".rsp") != std::string::npos){
			if (file.find("CFB") != std::string::npos){
				if (file.find("CFB128") != std::string::npos){
					mode = FastRijndael::CFB;
				}
				else{
					continue;
				}
			}
			else{
				if (file.find("CBC") != std::string::npos)	mode = FastRijndael::CBC;
				else if (file.find("OFB") != std::string::npos) mode = FastRijndael::OFB;
				else						mode = FastRijndael::ECB;
			}
			if (file.find("128.") != std::string::npos){
				ks = FastRijndael::K128;
				key_hexchar_size = 32;
				chKey = chKey128;
				cKey = cKey128;
			}
			if (file.find("192.") != std::string::npos){
				ks = FastRijndael::K192;
				key_hexchar_size = 48;
				chKey = chKey192;
				cKey = cKey192;				
			}
			else if (file.find("256.") != std::string::npos){
				ks = FastRijndael::K256;
				key_hexchar_size = 64;
				chKey = chKey256;
				cKey = cKey256;				
			}
			file = "./kat/" + file;
			ifstream namefile;
			namefile.open (file.c_str(), std::ios::binary);
			string line;
			while (!namefile.eof()){
				getline(namefile, line);
				for (int i = 0; i < line.size(); i++){
					if (line[i] == '\r'){
						line[i] = '\0';
					}
				}
				if (line.find("#") != std::string::npos){
					continue;
				}
				if (line.length() <= 1){
					continue;
				}
				if (line.find("ENCRYPT") != std::string::npos){
					encrypt = true;
					continue;
				}
				if (line.find("DECRYPT") != std::string::npos){
					encrypt = false;
					continue;
				}				
				if (line.find("COUNT") != std::string::npos){
					count = line;
					continue;
				}
				if (line.find("KEY") != std::string::npos){
					line = line.substr(6, line.size());				
					for(std::size_t i = 0; i < line.size()-1; i++){
						chKey[i] = line[i];
					} 
				        hexStringToCharString(chKey, key_hexchar_size, cKey);
					rijn_kat = FastRijndael(ks, FastRijndael::B128, mode);
					rijn_kat.makeKey(cKey);
				}
				if (line.find("IV") != std::string::npos){
					line = line.substr(5, line.size());				
					for (std::size_t i = 0; i < line.size()-1; i++){
						chIV[i] = line[i];
					}
					hexStringToCharString(chIV, 32, cIV);
					rijn_kat.setIV(cIV);
				}
				if (line.find("PLAINTEXT") != std::string::npos){
					line = line.substr(12, line.length());					
					if (encrypt){
						for (std::size_t i = 0; i < line.size()-1; i++){
							chBlock[i] = line[i];
						}
        					hexStringToCharString(chBlock, 32, cBlock);
						rijn_kat.encrypt(cBlock, blockLen);
					}
					else{
						for (std::size_t i = 0; i < line.size()-1; i++){
							chAnsw[i] = line[i];
						}
        					hexStringToCharString(chAnsw, 32, cAnsw);
						bool diff = false;
						for (std::size_t i = 0; i < 16; i++){
							if (cAnsw[i] != cBlock[i]){
								diff = true;
							}
						}
						if (diff){
							printf("%s %s %d\n", file.c_str(), count.c_str(), encrypt);
							for (std::size_t i = 0; i < 16; i++){
								printf("%.2x", cBlock[i]);
							}	printf("\n");
							for (std::size_t i = 0; i < 16; i++){
								printf("%.2x", cAnsw[i]);
							}	printf("\n");
							return(0);
						}
						rijn_kat.cleanUp();
					}
				}
				if (line.find("CIPHERTEXT") != std::string::npos){
					line = line.substr(13, line.length());					
					if (encrypt){
						for (std::size_t i = 0; i < line.size()-1; i++){
							chAnsw[i] = line[i];
						}
        					hexStringToCharString(chAnsw, 32, cAnsw);		
						bool diff = false;
						for (std::size_t i = 0; i < 16; i++){
							if (cAnsw[i] != cBlock[i]){
								diff = true;
							}
						}
						if (diff){
							printf("%s %s %d\n", file.c_str(), count.c_str(), encrypt);
							for (std::size_t i = 0; i < 16; i++){
								printf("%.2x", cBlock[i]);
							}	printf("\n");
							for (std::size_t i = 0; i < 16; i++){
								printf("%.2x", cAnsw[i]);
							}	printf("\n");
							return(0);
						}
						rijn_kat.cleanUp();
					}
					else{
						for (std::size_t i = 0; i < line.size()-1; i++){
							chBlock[i] = line[i];
						}
        					hexStringToCharString(chBlock, 32, cBlock);		
						rijn_kat.decrypt(cBlock, blockLen);
					}
				}
			}
			namefile.close();
		}
	}

	delete[] chKey128;
	delete[] cKey128;
	delete[] chKey192;
	delete[] cKey192;
	delete[] chKey256;
	delete[] cKey256;
	delete[] chIV;
	delete[] cIV;
	delete[] chBlock;
	delete[] cBlock;
	delete[] chAnsw;
	delete[] cAnsw;
	closedir(d);
	return(0);*/

	FastRijndael rijn(FastRijndael::K128, FastRijndael::B128, FastRijndael::ECB);
	unsigned char chKey[17] = "essasenhaehfraca";
//	char chKey[49] = "800000000000000000000000000000000000000000000000";
//        unsigned char* cKey = new unsigned char [16];
//        hexStringToCharString((unsigned char*)chKey, 48, cKey);

	rijn.makeKey(&chKey[0]);
	
//	char chIV[33] = "000102030405060708090a0b0c0d0e0f";
//	char chIV[33] = "80000000000000000000000000000000";
//	unsigned char* cIV = new unsigned char [16];
//	hexStringToCharString((unsigned char*)chIV, 32, cIV);

//	rijn.setIV(cIV);
	
	unsigned char chBlock[33] = "7bf094256426447110a04ee8eec18550"; 

        unsigned char* cBlock = new unsigned char [16];
        hexStringToCharString((unsigned char*)chBlock, 32, cBlock);
	int blockLength = 16;

//	printBlock1(cBlock, 16);	
	rijn.decrypt(cBlock, blockLength);
	printBlock1(cBlock, 16);
//	rijn.decrypt(cBlock);
//	printBlock1(cBlock, 16);

	return EXIT_SUCCESS;
}
