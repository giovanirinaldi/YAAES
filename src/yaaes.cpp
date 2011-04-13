#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include <cstring>
using namespace std;

#include "rijndael.h"

int main (int argc, char *argv[]){
	Rijndael r;
	timeval t1, t2;
/*	char input[1024];
	char ch[Rijndael::K128/8];
	unsigned char uch[Rijndael::K128/8];
	signed char sch[Rijndael::K128/8];*/
	unsigned char a[5] = "abcd";
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
	unsigned char ck [4][4] = {
		{ 0x2b, 0x7e, 0x15, 0x16 },
		{ 0x28, 0xae, 0xd2, 0xa6 },
		{ 0xab, 0xf7, 0x15, 0x88 },
		{ 0x09, 0xcf, 0x4f, 0x3c }
	};
	unsigned char** ck1 = new unsigned char* [4];
	for (int i = 0; i < 4; i++){	ck1[i] = new unsigned char[4];	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			ck1[i][j] = ck[i][j];
		}
	}
	r.makeKey(ck1, Rijndael::K128, Rijndael::B128);	
	for (int i = 0; i < 44; i++){
		for (int j = 0; j < 4; j++){
			printf("%x ", r._exp_key[i][j]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
