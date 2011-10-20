#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifndef EXTERN
#define EXTERN extern
#endif

#include "rijndael.h"

EXTERN Rijndael* rijn;

EXTERN unsigned char ** inputMatrix, ** keyMatrix, ** outputMatrix, ** stateMatrix;

EXTERN int round, maxRounds;

enum rijnOps {
		SB, SR, MC, ARK, NONE 
	};
	
static const rijnOps opsOrder[4] = {
	SB, SR, MC, ARK
};

EXTERN rijnOps nextOp, thisOp, previousOp;

#endif // __GLOBAL_H__
