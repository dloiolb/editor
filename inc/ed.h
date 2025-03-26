#ifndef COMMANDS_H
#define COMMANDS_H

// include files:

#include "node.h"

// external data types and variables:

// COMMANDS_H data types:

typedef struct Buffer {
    Node * head; // pointer to the first line (line 1)
    Node * tail; // pointer to the last line (line line_count)
    int line_count; // number of lines in buffer
} Buffer;  

// COMMANDS_H functions:

#endif