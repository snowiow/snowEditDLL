#include <stdlib.h>
#include <string.h>

#include "darray.h"

DArray *newDArray() {
    DArray *arr = (DArray*) malloc(sizeof(DArray));
    arr->length = 0;
    arr->capacity = 0;
    return arr;
}

void dArrayAppend(DArray *arr, const char *elem) {
    if (arr->length == 0) {
        arr->elems = (char**) malloc(10 * sizeof(char*));
        arr->capacity = 10 * sizeof(char*);

        uint i;
        for (i = 0; i < arr->capacity/sizeof(char*); i++){
            arr->elems[i] = NULL;
        }
    }
    if (arr->capacity <= (arr->length) * sizeof(char*)) {
        arr->elems = (char**) realloc(arr->elems, arr->capacity * 2);
        arr->capacity *= 2;
    }
    arr->elems[arr->length] = (char*) malloc(strlen(elem) * sizeof(char*));
    strcpy(arr->elems[arr->length], elem);
    arr->length++;
}

void dArrayRemove(DArray *arr, const uint index) {
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
