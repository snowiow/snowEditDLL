#include "lexer.h"
#include "global.h"
#include "set.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

DArray *tokenize(char* text) {
    DArray *d = newDArray();
    Set *s = newSet();
    ulong i;

    for (i = 0; i < strlen(text); i++) {
        switch(text[i]) {
            case '/':
                i++;
                switch(text[i]) {
                    case '/':
                        while (text[i] != '\n') {
                            i++;
                        }
                        break;
                    case '*':
                        while (i < strlen(text) || (text[i] == '/' && text[i+1] == '*')) {
                            i++;
                        }
                        i++;
                        break;

                    default:
                        break;
                }
                break;

            case '$':
            case '@':
                tokenizeWord(s, &i, text);
                break;

            default:
                 break;
        }
    }
    return d;
}

void tokenizeWord(Set *s, ulong *i, char *text) {
    bool eow;
    printf("%s", text);
    ulong start = *i;
    ulong end = start + 1;
    printf("test\n");
    if (i != NULL) {
        while (*i < strlen(text) && !eow)  {
            switch(text[*i]) {
                case ' ':
                case ',':
                case '.':
                case '+':
                case '-':
                case '*':
                case '/':
                case '=':
                case ';':
                case ':':
                case '(':
                case ')':
                case ']':
                case '[':
                case '{':
                case '}':
                    end = *i;
                    eow= true;
                    (*i)++;
                    break;
                default:
                    (*i)++;
                    break;
            }
        }
        if (eow)
            printf("test\n");
        char cur[end - start + 2];
        strncpy(cur, text+start, end);
        strcat(cur, "\0");
        printf("%s", cur);
        setInsert(s, cur);
    }
}
