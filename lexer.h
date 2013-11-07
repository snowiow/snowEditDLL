#ifndef LEXER_H
#define LEXER_H

#include "darray.h"
#include "set.h"

DArray *tokenize(char* text);
void tokenizeWord(Set *s, ulong *i, char *text);

#endif
