#ifndef TOKENIZE_H
#define TOKENIZE_H

// include files:

#include "macros.h"

// TOKENIZE_H macros:

#define MAX_TOKENS 20
#define BUFFER_SIZE 2048

// TOKENIZE_H data types:

// TOKENIZE_H functions:

void collect_tokens(char * line, char * arr[MAX_TOKENS], int * count);
void concatTokens(char * concatstring, char * arr[], int count);

// external data types and variables:

#endif