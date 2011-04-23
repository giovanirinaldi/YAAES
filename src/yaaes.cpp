#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include <cstring>
#include <cctype>
using namespace std;

#include "rijndael.h"

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

int main (int argc, char *argv[]){
	Rijndael r(Rijndael::K192, Rijndael::B128);
	timeval t1, t2;
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
	unsigned char bk_round1 [4][4] = {
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
	unsigned char ck_demo [4][4] = {
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
	};

//	unsigned char ckoo[25] = "012345678901234567890123";
//	unsigned char bkoo[17] = "Texto para teste";
	// vector to block -> by column and by line
	// vector to key -> by line and by column
	unsigned char** ck1 = new unsigned char* [6];
	unsigned char** bk1 = new unsigned char* [6];
	for (int i = 0; i < 6; i++){	ck1[i] = new unsigned char[4];	bk1[i] = new unsigned char[4];}
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 4; j++){
			ck1[i][j] = ck[i][j];
			bk1[i][j] = bk[i][j];
		}
	}

	unsigned char ck192h[49] = "000102030405060708090a0b0c0d0e0f1011121314151617";
//	unsigned char ck192h[49] = "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b";
	unsigned char ck192[25];
	hexStringToCharString(ck192h, 49, ck192);
	//for (int i = 0; i < 24; i++)	printf("%x ", ck192[i]);
	//printf("\n");
	unsigned char bk128h[33] = "00112233445566778899aabbccddeeff";
	unsigned char bk128[17];
	hexStringToCharString(bk128h, 33, bk128);
	r.makeKey(ck192);
	r.encrypt(bk1);
//	r.decrypt(bk1);
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
	gettimeofday(&t2, 0);
	//printf("aqui\n");fflush(stdout);
	//printf("%s\n", ckoo);
//	printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%x ", bk1[i][j]);
		}
		printf("\n");
	}
/*	for (int i = 0; i < 4; i++){
		delete[] bk1[i];
		delete[] ck1[i];
	}
	delete[] bk1;
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
