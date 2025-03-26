#ifndef COMMANDS_H
#define COMMANDS_H

// include files:

#include "macros.h"
#include "ed.h"

// external data types and variables:

typedef struct Buffer Buffer;
extern Buffer buffer;
extern int current_line;
extern char filename[MAX_FILENAME_LENGTH]; 

// COMMANDS_H macros:

// COMMANDS_H data types:

// COMMANDS_H functions:

int command_E(char * name);

#endif