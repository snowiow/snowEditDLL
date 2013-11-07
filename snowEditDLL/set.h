#ifndef SET_H
#define SET_H

#include "set.h"
#include "darray.h"
#include <stdbool.h>

typedef struct {
    //the elems of the set
    DArray **elems;
    //length of the set and not how many entries the set has
    uint length;
    //the current capacity of the set
    uint curCapacity;
    //the maximum capicity of the set
    uint totalCapacity;
} Set;

Set *newSet();
void setInsert(Set *set, char* value);
void setRealloc(Set * set);
uint sdbm(char *str);
DArray *getElems(Set *set);
void setFree(Set *set);

#endif
