#ifndef COMMANDS_H
#define COMMANDS_H

// include files:

#include "macros.h"

// external data types and variables:

typedef struct Buffer Buffer;
extern Buffer ed_buffer;
extern int ed_currentline;
extern char ed_filename[MAX_FILENAME_LENGTH]; 

// COMMANDS_H macros:

// COMMANDS_H data types:

// COMMANDS_H functions:

int command_a();
int command_h();
int command_E(char * name);
int command_period();
int command_equal();
int command_w();

#endif