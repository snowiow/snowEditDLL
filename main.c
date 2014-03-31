#include <stdio.h>
#include <string.h>

#include "set.h"
#include "lexer.h"
#include "mempool.h"


int main(int argc, const char* argv[]) {
    // MemPool *m = newMemPool();
    // char* test = memPoolAlloc(m, 5);
    // strcpy(test, "$abcd");


    // char* test2 = memPoolAlloc(m, 6);
    // strcpy(test2, "$wasge");

    // printf("%s\n", test);
    // printf("%s\n", test2);
    // memPoolFree(m);
    // MemPool *m =newMemPool();
    // DArray *arr = newDArray(m);
    // dArrayAppend(arr, "hallo");
    // printf("Neues Array initialisiert mit Element: %s\n", arr->elems[0]);
    // printf("Groese des Arrays: %d\n", arr->capacity);

    // dArrayAppend(arr, "new");
    // printf("Neues Element hinzugefuegt: %s\n", arr->elems[1]);

    // dArrayAppend(arr, "123");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[2]);
    // dArrayAppend(arr, "a");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[3]);
    // dArrayAppend(arr, "b");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[4]);
    // dArrayAppend(arr, "c");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[5]);
    // dArrayAppend(arr, "d");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[6]);
    // dArrayAppend(arr, "e");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[7]);
    // dArrayAppend(arr, "f");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[8]);
    // dArrayAppend(arr, "g");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[9]);
    // dArrayAppend(arr, "h");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[10]);
    // printf("\n");

    // uint i;
    // for (i = 0; i < arr->length; i++)
    //     printf("Array: %s\n", arr->elems[i]);

    // dArrayFree(arr);
    // arr = NULL;
    // printf("Array freed\n");
    // memPoolFree(m);
    // m = NULL;
    // printf("MemPool freed\n");


    // printf("Set Tests: \n");

    // m = newMemPool();
    // Set *s = newSet(m);
    // printf("Initiale Laenge des Sets: %d\nInitiale curCapicity: %d\nInitiale totalCapacity: %d\n", s->length, s->curCapacity, s->totalCapacity);

    // setInsert(s, "123test");
    // setInsert(s, "es geht");
    // setInsert(s, "123test");
    // DArray *out = getElemsFromSet(s);

    // for (i = 0; i < out->length; i++) {
    //     printf("%s\n", out->elems[i]);
    // }

    // setFree(s);
    // s = NULL;
    // dArrayFree(out);
    // out = NULL;
    // memPoolFree(m);
    // m = NULL;

    // printf("Tokenize Tests: \n");
    // DArray *test3 = tokenize("$hallo\n$fertig\n$hunger\n__cif(){$nur}");
    // printf("Found Variables:\n");
    // uint i;
    // for (i = 0; i < test3->length; i++) {
    //     printf("%s\n", test3->elems[i]);
    // }
    // memPoolFree(test3->m);
    // dArrayFree(test3);
    // test3 = NULL;

    printf("Final test with file:\n");
    FILE *quelle;
    char puffer[80], text[4000] = "";

    if ((quelle=fopen("test2.rs","r")) == NULL) {
        // fprintf(stderr, "Kann test.rs nicht oeffnen\n");
        return -1;
    }

    while (fgets(puffer, 80, quelle))
        strcat(text, puffer);

    fclose(quelle);

    DArray *result = tokenize(text);
    uint i;
    for (i = 0; i < result->length; i++) {
        printf("%s\n", result->elems[i]);
    }
    memPoolFree(result->m);
    dArrayFree(result);

    return 0;
}
