#ifndef MEMPOOL_H
#define MEMPOOL_H
#include "global.h"

typedef struct {
    //The current length of the Mempool
    uint curLength;
    //The total length of the Mempool
    uint totalLength;
    //The array itself
    char* memory;

} MemPool;

MemPool *newMemPool();
char *memPoolAlloc(MemPool *mempool, const uint length);
void memPoolFree(MemPool * mempool);

#endif
