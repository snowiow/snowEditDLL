#ifndef DARRAY_H
#define DARRAY_H
#include "global.h"

typedef struct {
    //The count of elems
    uint length;
    //The actual capacity of dArray
    uint capacity;
    //The array itself
    char** elems;

} DArray;

DArray *newDArray();

void dArrayAppend(DArray *arr, char *elem);
void dArrayRemove(DArray *arr, uint index);
void dArrayFree(DArray *arr);

#endif
