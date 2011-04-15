#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include <cstring>
using namespace std;

#include "rijndael.h"

int mul(int x, int y) {
    int r = 0;
    for (;y!=0;y>>=1,x<<=1)
        if (y&1)
            r+=x;
    return r;
}

int main (int argc, char *argv[]){
	Rijndael r;
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
	unsigned char ck [4][4] = {
		{ 0x00, 0x01, 0x02, 0x03 },
		{ 0x04, 0x05, 0x06, 0x07 },
		{ 0x08, 0x09, 0x0a, 0x0b },
		{ 0x0c, 0x0d, 0x0e, 0x0f }
	};
	// vector to block -> by column and by line
	// vector to key -> by line and by column
	unsigned char** ck1 = new unsigned char* [4];
	unsigned char** bk1 = new unsigned char* [4];
	for (int i = 0; i < 4; i++){	ck1[i] = new unsigned char[4];	bk1[i] = new unsigned char[4];}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			ck1[i][j] = ck[i][j];
			bk1[i][j] = bk[i][j];
		}
	}
	gettimeofday(&t1, 0);
	r.makeKey(ck1, Rijndael::K128, Rijndael::B128);	
	r.encrypt(bk1);
	r.decrypt(bk1);
	gettimeofday(&t2, 0);
	printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%x ", bk1[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 4; i++){
		delete[] bk1[i];
		delete[] ck1[i];
	}
	delete[] bk1;
	delete[] ck1;

//	unsigned char a[1] = {0xbf};
/*	a[0] = a[0] << 1;		mult por 2
	a[0] ^= 0x1b;*/ 
	
//mult por 3
/*	a[0] = (a[0] << 1) ^ a[0];
	a[0] ^= 0x1b;*/
//	printf("%x\n", a[0]);
	return EXIT_SUCCESS;
}
