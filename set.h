#ifndef SET_H
#define SET_H

#include <stdbool.h>

#include "set.h"
#include "darray.h"
#include "mempool.h"

typedef struct {
    //the elems of the set
    DArray **elems;
    //length of the set and not how many entries the set has
    uint length;
    //the current capacity of the set
    uint curCapacity;
    //the maximum capicity of the set
    uint totalCapacity;
    MemPool *m;
} Set;

Set *newSet(MemPool *m);
void setInsert(Set *set, const char* value);
void setRealloc(Set * set);
uint sdbm(const char *str);
DArray *getElemsFromSet(const Set *set);
void setFree(Set *set);

#endif
