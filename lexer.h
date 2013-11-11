#ifndef LEXER_H
#define LEXER_H

#include "darray.h"
#include "set.h"

DArray *tokenize(const char* text);
void tokenizeWord(Set *s, ulong *i, const char *text);

#endif
