#ifndef NODE_H
#define NODE_H

// include files:

#include "macros.h"
// #include "ed.h"

// NODE_H macros:

// NODE_H data types:

typedef struct Node Node;
struct Node {
    char * line;
    Node * next;
    Node * prev;
};

// NODE_H functions:

Node * create_node(Node * prev, Node * next, const char * line);
int free_node(Node * node);
int free_all_nodes();
Node * nth_node(int n);
int num_lines();
int num_chars();

// external data types and variables:

extern Node * ed_buffer_head;
extern Node * ed_buffer_current;
extern char ed_filename[MAX_FILENAME_LENGTH]; 

#endif