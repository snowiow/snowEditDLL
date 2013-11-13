#ifndef DARRAY_H
#define DARRAY_H

#include "global.h"
#include "mempool.h"

typedef struct {
    //The count of elems
    uint length;
    //The actual capacity of dArray
    uint capacity;
    //The array itself
    char** elems;

    MemPool *m;

} DArray;

DArray *newDArray(MemPool *m);

void dArrayAppend(DArray *arr, const char *elem);
void dArrayFree(DArray *arr);

#endif
