#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lexer.h"
#include "global.h"
#include "mempool.h"
#include "darrays.h"


DArray *tokenize(const char* text) {
    //describes how deep the scope of curly brackets is
    int level = 0;
    //A Set created on each scope level
    DArrayS *levelSets = newDArrayS();
    dArraySAppend(levelSets);
    int cursorFound = -1;
    ulong i = 0;
    while (i < strlen(text)) {
            switch(text[i]) {
                case '/':
                    i += 1;
                    switch(text[i]) {
                        case '/':
                            while (i < strlen(text) && text[i] != '\n') {
                                i += 1;
                            }
                            break;
                        case '*':
                            while (i < strlen(text) && (text[i] != '/' && text[i+1] != '*')) {
                                i += 1;
                            }
                            i += 1;
                            break;
                        default:
                            i += 1;
                            break;
                    }
                    break;
                case '{':
                    if (cursorFound == -1)
                        dArraySAppend(levelSets);
                    level += 1;
                    i += 1;
                    break;
                case '}':
                    if (cursorFound == -1)
                        dArraySDelete(levelSets, level);
                    else
                        cursorFound = -2;
                    level -= 1;
                    i += 1;
                    break;
                case '_':
                    i += 1;
                    if (text[i] == '_') {
                        i += 1;
                        if (text[i] == 'c') {
                            cursorFound = level;
                            i += 1;
                        }
                    }
                    break;
                case '$':
                case '@':
                   if (cursorFound == -1 || (level == 0 && cursorFound != 2)) {
                    tokenizeWord(levelSets->elems[level], &i, text, &cursorFound, level);
                    }
                    else {
                        i += 1;
                    }
                    break;
                default:
                    i += 1;
                    break;
            }
    }
    // for (i = 0; i < cursorFound; i++)
    //     dArraySDelete(levelSets, i);
    DArray *arr = createDArrayFromDArrayS(levelSets);
    dArraySFree(levelSets);
    return arr;
}

void tokenizeWord(Set *s, ulong *i, const char *text, int *cursorFound, const int level) {
    bool eow = false;
    ulong start = *i;
    ulong end = start;
    ulong ignoreStart = 0;
    ulong ignoreEnd = 0;
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
                    break;
                case '_':
                    ignoreStart = (*i);
                    (*i) += 1;
                    if (text[*i] == '_') {
                        (*i) += 1;
                        if (text[*i] == 'c') {
                            (*cursorFound) = level;
                            (*i) += 1;
                            ignoreEnd = (*i);

                        }
                    }
                    break;
                default:
                    (*i) += 1;
                    break;
            }
        }
        end = (*i);
        if (start+1 == end)
            return;
        if (ignoreEnd > 0) {
            //3 is the range of characters of the cursor symbol
            char cur[end - start - 3 + 1];
            strncpy(cur, text+start, ignoreStart - start);
            // uint j;
            // for (uint j = 0; j < count; ++i)
            // {
            //     /* code */
            // }
            strncpy(cur + (ignoreStart - start), text + ignoreEnd, end - ignoreEnd);
            cur[end-start - 3] = '\0';

            setInsert(s, cur);
        }
        else {
            char cur[end - start + 1];
            strncpy(cur, text+start, end - start);
            cur[end-start] = '\0';
            setInsert(s, cur);
        }
    }
}
