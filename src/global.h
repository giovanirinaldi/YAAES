#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifndef EXTERN
#define EXTERN extern
#endif

// place your code here
#include "rijndael.h"

EXTERN Rijndael* rijn;

EXTERN unsigned char ** inputMatrix, ** keyMatrix, ** outputMatrix, ** stateMatrix;

#endif // __GLOBAL_H__
