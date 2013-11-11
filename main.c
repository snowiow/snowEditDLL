#include <stdio.h>
#include <string.h>

#include "set.h"
#include "lexer.h"


int main(int argc, const char* argv[]) {
    // DArray *arr = newDArray();
    // dArrayAppend(arr, "hallo");
    // printf("Neues Array initialisiert mit Element: %s\n", arr->elems[0]);
    // printf("Groese des Arrays: %d\n", arr->capacity);

    // dArrayAppend(arr, "new");
    // printf("Neues Element hinzugefuegt: %s\n", arr->elems[1]);

    // dArrayAppend(arr, "123");
    // printf("Neues Element hinzugefuegt:%s\n", arr->elems[2]);
    // dArrayAppend(arr, "a");
    // dArrayAppend(arr, "b");
    // dArrayAppend(arr, "c");
    // dArrayAppend(arr, "d");
    // dArrayAppend(arr, "e");
    // dArrayAppend(arr, "f");
    // dArrayAppend(arr, "g");
    // dArrayAppend(arr, "h");
    // printf("\n");

    // dArrayRemove(arr, 1);
    // uint i;
    // for (i = 0; i < arr->length; i++){
    //     printf("Array nach Delete: %s\n", arr->elems[i]);
    // }

    // dArrayFree(arr);
    // arr = NULL;


    // printf("Set Tests: \n");
    // Set *s = newSet();
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

    // printf("Tokenize Tests: \n");
    // DArray *test = tokenize("$i = 1; //$123\n/* $567 */ $j\n 123 45\n");
    // printf("Found Variables:\n");

    // for (i = 0; i < test->length; i++) {
    //     printf("%s\n", test->elems[i]);
    // }
    // dArrayFree(test);
    // test = NULL;

    // printf("Final test with file:\n");
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
    for (i = 0; i < 2; i++) {
        printf("%s\n", result->elems[i]);
    }

    dArrayFree(result);

    return 0;
}
