#include "set.h"
#include "lexer.h"
#include <stdio.h>

int main(int argc, const char* argv[]) {
    DArray *arr = newDArray();
    dArrayAppend(arr, "hallo");
    printf("Neues Array initialisiert mit Element: %s\n", arr->elems[0]);
    printf("Groese des Arrays: %d\n", arr->capacity);

    char neu[] = "new";
    dArrayAppend(arr, neu);
    printf("Neues Element hinzugefuegt: %s\n", arr->elems[1]);
    char neu2[] = "123";

    dArrayAppend(arr, neu2);
    printf("Neues Element hinzugefuegt:%s\n", arr->elems[2]);

    printf("\n");

    dArrayRemove(arr, 1);
    uint i;
    for (i = 0; i < arr->length; i++){
        printf("Array nach Delete: %s\n", arr->elems[i]);
    }

    dArrayFree(arr);


    printf("Set Tests: \n");
    Set *s = newSet();
    printf("Initiale Laenge des Sets: %d\nInitiale curCapicity: %d\nInitiale totalCapacity: %d\n", s->length, s->curCapacity, s->totalCapacity);

    setInsert(s, "123test");
    setInsert(s, "es geht");
    setInsert(s, "123test");
    DArray *out = getElems(s);

    for (i = 0; i < out->length; i++) {
        printf("%s\n", out->elems[i]);
    }

    setFree(s);
    dArrayFree(out);

    printf("Tokenize Tests: \n");
    DArray *test = tokenize("$i = 1; //$123\n /* $567 */ $j\n 123 45");
    // for (i = 0; i < test->length; i++) {
    //     printf("%s\n", test->elems[i]);
    // }
    dArrayFree(test);

    return 0;
}
