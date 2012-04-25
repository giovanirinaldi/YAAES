#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifndef EXTERN
#define EXTERN extern
#endif

#include "rijndael/rijndael.h"

#include <QMessageBox>
#include <QDebug>

EXTERN Rijndael* rijn;

EXTERN unsigned char ** inputMatrix, ** keyMatrix, ** outputMatrix, ** stateMatrix, ** previousMatrix, ** nextMatrix;

EXTERN int round, maxRounds, maxRoundByKey;

enum rijnOps {
		SB, SR, MC, ARK , STOP
	};
	
EXTERN rijnOps op;

EXTERN bool forward;

EXTERN rijnOps nextOp, thisOp, previousOp;

#endif // __GLOBAL_H__
