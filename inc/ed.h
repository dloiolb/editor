#ifndef COMMANDS_H
#define COMMANDS_H

// include files:

#include "macros.h"
#include "node.h"
// #include "commands.h"

// external data types and variables:

// typedef struct Node Node;

// COMMANDS_H macros:

// COMMANDS_H data types:

typedef struct Buffer {
    Node * head; // pointer to the first line (line 1)
    // Node * tail; // pointer to the last line (line line_count)
    int line_count; // number of lines in ed_buffer
} Buffer;  


// COMMANDS_H functions:

#endif