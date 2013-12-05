#ifndef DARRAYS_H
#define DARRAYS_H

#include "global.h"
#include "set.h"

typedef struct{
    //The count of elems
    uint length;
    //The actual capacity of dArray
    uint capacity;
    //The pointer to the sets
    Set **elems;

} DArrayS;


DArrayS *newDArrayS();
void dArraySAppend(DArrayS *arr);
void dArraySDelete(DArrayS *arr, uint level);
DArray *createDArrayFromDArrayS(DArrayS *arr);
void dArraySFree(DArrayS *arr);

#endif
