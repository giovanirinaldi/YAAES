//#include "../res/x_sbox_diff_coded.h"
//#include "../res/y_sbox_diff_coded.h"


class RijndaelAttacker {
	public:
		void copyBlock(unsigned char* block_src, unsigned char* block_dest);
		bool blocksAreEqual(unsigned char* block1, unsigned char* block2);
		void copyMainDiagonalAndXorGuesses(unsigned char* k0, unsigned char** tempBlock_arrays, unsigned char** plaintexts, int num_texts);
		void diff(unsigned char* block1, unsigned char* block2, unsigned char* dest);
		void solveMixColumnFor2RoundPhase2(unsigned char * k2, unsigned char * u2);
		unsigned char xSboxDiff(unsigned char a, unsigned char b);
		unsigned char ySboxDiff(unsigned char a, unsigned char b);
		bool sboxDiffsMatches(unsigned char** tempBlock_arrays, unsigned char* tempBlockDiff12, unsigned char* tempBlockDiff13, unsigned char * invCipherDiff12, unsigned char* invCipherDiff13, unsigned char* k1, int from, int to);
                bool findKeyForTwoRounds(unsigned char** plaintexts, unsigned char** ciphertexts, int num_texts, unsigned char* k0found,
                                         short int k0b00from, short int k0b00to, short int k0b05from, short int k0b05to, short int k0b07from, short int k0b07to,
                                         short int k0b08from, short int k0b08to, short int k0b10from, short int k0b10to, short int k0b15from, short int k0b15to);
	
	private:
		
		unsigned char* k1_12_1;
		unsigned char* k1_12_2;
		unsigned char* k1_13_1;
		unsigned char* k1_13_2;
                unsigned char poss_x;
};
