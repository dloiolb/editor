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

void error_msg();
void command_E(char * name);
void command_q();
void command_h();
void command_period();
void command_equal();
void command_w();
void command_a(int n);

#endif