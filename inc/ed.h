#ifndef COMMANDS_H
#define COMMANDS_H

// include files:

#include "macros.h"
#include "node.h"

// #include "commands.h"

// external data types and variables:

// COMMANDS_H macros:

// COMMANDS_H data types:

typedef struct Buffer {
    Node * head; // pointer to the first line (line 1)
    Node * current; // pointer to the current line
} Buffer;  

// COMMANDS_H functions:

#endif