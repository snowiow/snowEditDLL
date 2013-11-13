#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lexer.h"
#include "global.h"
#include "mempool.h"


DArray *tokenize(const char* text) {
    MemPool *m = newMemPool();
    Set *s = newSet(m);

    ulong i = 0;

    while (i < strlen(text)) {
        switch(text[i]) {
            case '/':
                i++;
                switch(text[i]) {
                    case '/':
                        while (i < strlen(text) && text[i] != '\n') {
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
    DArray *arr = getElemsFromSet(s);
    setFree(s);
    return arr;
}

void tokenizeWord(Set *s, ulong *i, const char *text) {
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
                    eow = true;
                    (*i)++;
                    break;
                default:
                    (*i)++;
                    break;
            }
        }
        end = (*i);
        char cur[end - start + 1];
        strncpy(cur, text+start, end - start);
        cur[end-start] = '\0';
        setInsert(s, cur);
    }
}
