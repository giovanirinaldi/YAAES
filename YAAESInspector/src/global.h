#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifndef EXTERN
#define EXTERN extern
#endif

#include "../Rijndael/fast-rijndael-1d/fast-rijndael-1d.h"

#include <QMessageBox>
#include <QDebug>

EXTERN FastRijndael* rijn;

//EXTERN unsigned char ** inputMatrix, ** keyMatrix, ** outputMatrix, ** stateMatrix, ** previousMatrix, ** nextMatrix;
EXTERN unsigned char * inputMatrix, * keyMatrix, * outputMatrix, * stateMatrix, * previousMatrix, * nextMatrix;

EXTERN int round, maxRounds, maxRoundByKey;

enum rijnOps {
		SB, SR, MC, ARK , STOP
	};
	
EXTERN rijnOps op;

EXTERN bool forward;

EXTERN rijnOps nextOp, thisOp, previousOp;

EXTERN FastRijndael::KeySize ks_temp;

#endif // __GLOBAL_H__
