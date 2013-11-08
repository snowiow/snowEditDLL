#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "set.h"


uint sdbm(char *str) {
    uint hash = 0;
    int c = 0;
    while ((c = *str++))
        hash = c + (hash << 6) + (hash << 16) - hash;
    return hash;
}

void setRealloc(Set *set) {
    set->elems = (DArray**) realloc(set->elems, set->totalCapacity * 2);
    set->length *= 2;
    set->totalCapacity *= 2;
    uint i;
    for (i = set->length/2 + 1; i < set->length; i++)
        set->elems[i] = NULL;
}

Set *newSet() {
    Set *set = (Set*) malloc(sizeof(Set));
    set->elems = (DArray**) malloc(10 * sizeof(DArray*));
    set->length = 10;
    set->curCapacity = 0;
    set->totalCapacity = 10 * sizeof(DArray*);

    uint i;
    for (i = 0; i < set->length; i++){
        set->elems[i] = NULL;
    }

    return set;
}

void setInsert(Set *set, char* value) {
    //realloc if 50% of available memory reached
    // printf("curCapacity: %d > totalCapacity: %d /2", set->curCapacity, set->totalCapacity);
    if (set->curCapacity > set->totalCapacity / 2) {
        setRealloc(set);
    }
    /*
    * calculate hash with sdbm algorithm and set range to the currently
    * reserved space
    */
    // printf("sdbm(%d) mod set->totalCapacity(%d) /sizeofDarray(%d)\n", sdbm(value), set->totalCapacity, size);
    uint hash = (uint) (sdbm(value) % (set->totalCapacity/sizeof(DArray)));

    if (set->elems[hash] == NULL) {
        set->elems[hash] = newDArray();
        dArrayAppend(set->elems[hash], value);
        set->curCapacity += sizeof(DArray*);
    }
    else {
        uint i = 0;
        bool containsElem = false;
        while (i < set->elems[hash]->length && !containsElem) {
            if (strcmp(set->elems[hash]->elems[i], value) == 0) {

                containsElem = true;
            }
            i++;
        }
        if (!containsElem)
            dArrayAppend(set->elems[hash], value);
   }
}

DArray *getElemsFromSet(Set *set) {
    DArray *result = newDArray();
    uint i = 0;
    uint j;
    for (i = 0; i < set->length; i++) {
        if (set->elems[i] != NULL) {
            for (j = 0; j < set->elems[i]->length; j++)
                dArrayAppend(result, set->elems[i]->elems[j]);
        }
    }
    return result;
}


void setFree(Set *set) {
    uint i;
    for (i = 0; i < set->length; i++) {
        if(set->elems[i] != NULL)
            dArrayFree(set->elems[i]);
    }
    free(set->elems);
    set->elems = NULL;
    free(set);
}
