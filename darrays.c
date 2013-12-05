#include <stdlib.h>

#include "darrays.h"
#include "darray.h"

DArrayS *newDArrayS() {
    DArrayS *arr = (DArrayS*) malloc(sizeof(DArrayS));
    arr->elems = (Set**) malloc(2 * sizeof(Set*));
    arr->length = 0;
    arr->capacity = 2;

    uint i;
    for (i = 0; i < arr->capacity; i++){
        arr->elems[i] = NULL;
    }

    return arr;
}

void dArraySAppend(DArrayS *arr) {
    if (arr->capacity <= arr->length) {
        arr->elems = (Set**) realloc(arr->elems, arr->capacity * sizeof(Set*) * 2);
        arr->capacity *= 2;
        uint i;
        for (i = arr->capacity / 2 + 1; i < arr->capacity; i++) {
            arr->elems[i] = NULL;
        }

    }
    MemPool *m = newMemPool();
    Set *s = newSet(m);
    arr->elems[arr->length] = s;
    arr->length++;
}

void dArraySDelete(DArrayS *arr, uint level) {
    if (arr->elems[level] != NULL) {
        if (arr->elems[level]->m != NULL)
            memPoolFree(arr->elems[level]->m);
        setFree(arr->elems[level]);
    }
    uint i;
    for (i = level; i < arr->length - 1; i++)
        arr->elems[level] = arr->elems[level + 1];
    arr->length -= 1;
}

DArray *createDArrayFromDArrayS(DArrayS *arr) {
    uint i;
    for (i = 1; i < arr->length; i++) {
        setAppend(arr->elems[0], arr->elems[i]);
    }

    DArray *d = getElemsFromSet(arr->elems[0]);
    return d;
}

void dArraySFree(DArrayS *arr) {
    if (arr != NULL) {
        if (arr->elems != NULL) {
            uint i;
            for (i = 0; i < arr->length; i++) {
                memPoolFree(arr->elems[i]->m);
                setFree(arr->elems[i]);
            }
            free(arr->elems);
        }
        free(arr);
    }
}
