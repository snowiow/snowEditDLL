#include <stdlib.h>
#include <string.h>

#include "darray.h"

DArray *newDArray(MemPool *m) {
    DArray *arr = (DArray*) malloc(sizeof(DArray));
    arr->elems = NULL;
    arr->length = 0;
    arr->capacity = 0;
    arr->m = m;
    return arr;
}

void dArrayAppend(DArray *arr, const char *elem) {
    if (arr->length == 0) {
        arr->elems = (char**) malloc(2 * sizeof(char*));
        arr->capacity = 2 * sizeof(char*);

        uint i;
        for (i = 0; i < arr->capacity/sizeof(char*); i++){
            arr->elems[i] = NULL;
        }
    }
    if (arr->capacity <= (arr->length) * sizeof(char*)) {
        arr->elems = (char**) realloc(arr->elems, arr->capacity * 2);
        arr->capacity *= 2;
    }
    arr->elems[arr->length] = memPoolAlloc(arr->m, strlen(elem));
    strcpy(arr->elems[arr->length], elem);
    arr->length++;
}

void dArrayFree(DArray *arr) {
    if (arr != NULL) {
        if (arr->elems != NULL){
            free(arr->elems);
        }
        free(arr);
    }
}
