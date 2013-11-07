#include "darray.h"
#include <stdlib.h>
#include <string.h>

DArray *newDArray() {
    DArray *arr = (DArray*) malloc(sizeof(DArray));
    arr->length = 0;
    arr->capacity = 0;
    return arr;
}

void dArrayAppend(DArray *arr, char *elem) {
    if (arr->length == 0) {
        arr->elems = (char**) malloc(sizeof(char*) * 10);
        arr->capacity = sizeof(arr->elems);
    }
    if (arr->capacity < (arr->length + 1) * sizeof(char*)) {
        arr->elems = (char**) realloc(arr->elems, sizeof(arr->elems) * 2);
        arr->capacity = sizeof(arr->elems);
    }
    arr->elems[arr->length] = (char*) malloc(strlen(elem) * sizeof(char));
    strcpy(arr->elems[arr->length], elem);
    arr->length++;
}

void dArrayRemove(DArray *arr, uint index) {
    uint i;
    for(i = index; i < arr->length; i++) {
        arr->elems[i] = arr->elems[i+1];
    }
    arr->length--;
}

void dArrayFree(DArray *arr) {
    if (arr != NULL) {
        if (arr->elems != NULL){
            uint i;
            for (i = 0; i < arr->length; i++) {
                free(arr->elems[i]);
            }
            free(arr->elems);
        }
        free(arr);
    }
}
