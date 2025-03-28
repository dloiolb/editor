#ifndef NODE_H
#define NODE_H

// include files:

#include "macros.h"
// #include "ed.h"

// external data types and variables:

typedef struct Buffer Buffer;
extern Buffer ed_buffer; 
extern int ed_currentline;
extern char ed_filename[MAX_FILENAME_LENGTH]; 

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
int free_n_nodes(int first_line, int last_line);
int print_nth_node(int n, Node * ed_buffer_head);

#endif