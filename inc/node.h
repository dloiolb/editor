#ifndef NODE_H
#define NODE_H

typedef struct Node Node;

struct Node {
    char * line;
    Node * next;
    Node * prev;
};
  

typedef struct Buffer Buffer;

extern Buffer buffer;

typedef struct Node Node;
int create_node(Node * prev, Node * next, const char * line);
int free_node(Node * node);
int free_n_nodes(int first_line, int last_line);
int print_nth_node(int n, Node * buffer_head);

#endif