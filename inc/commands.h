#ifndef COMMANDS_H
#define COMMANDS_H

// include files:

#include "macros.h"

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
void command_f(char * name);
void command_wq();

void command_a(int n);
void command_c(int n, int m);
void command_d(int n, int m);

// external data types and variables:

extern Node * ed_buffer_head;
extern Node * ed_buffer_current;
extern char ed_filename[MAX_FILENAME_LENGTH]; 

#endif