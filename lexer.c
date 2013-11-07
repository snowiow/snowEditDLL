#include "lexer.h"
#include "global.h"
#include "set.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

DArray *tokenize(char* text) {
    Set *s = newSet();
    ulong i = 0;

    while (i < strlen(text)) {
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
                        while (i < strlen(text) && (text[i] != '/' && text[i+1] != '*')) {
                            i++;
                        }
                        i++;
                        break;

                    default:
                        i++;
                        break;

                }
                break;

            case '$':
            case '@':
                tokenizeWord(s, &i, text);
                break;

            default:
                i++;
                break;
        }
    }

    return getElemsFromSet(s);
}

void tokenizeWord(Set *s, ulong *i, char *text) {
    bool eow = false;
    ulong start = *i;
    ulong end = start;
    if (i != NULL) {
        while (*i < strlen(text) && !eow)  {
            switch(text[*i]) {
                case ' ':
                case '\n':
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
                    end = (*i);
                    eow= true;
                    (*i)++;
                    break;
                default:
                    (*i)++;
                    break;
            }
        }
        char cur[end - start + 1];
        strncpy(cur, text+start, end);
        cur[end-start] = '\0';
        setInsert(s, cur);
    }
}
