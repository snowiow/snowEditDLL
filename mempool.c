#include <stdlib.h>

#include "mempool.h"

MemPool *newMemPool() {
    MemPool *mempool = (MemPool*) malloc(sizeof(MemPool));
    mempool->curLength = 0;

    mempool->memory = (char*) malloc(512 * sizeof(char));
    mempool->totalLength = 512;

    return mempool;
}

char* memPoolAlloc(MemPool *mempool, const uint length) {
    uint oldLength = mempool->curLength;

    if (mempool->totalLength <= oldLength + length + 1) {
        mempool->memory = (char*) realloc(mempool->memory, mempool->totalLength * 2);
        mempool->totalLength *= 2;
    }
    mempool->curLength += length + 1;

    return &(mempool->memory[oldLength]);
}

void memPoolFree(MemPool *mempool) {
    free(mempool->memory);
    free(mempool);
    // mempool->memory = NULL;
    // mempool = NULL;
}
