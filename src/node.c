#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "ed.h"

// struct {
//   Node * head;
//   Node * tail;
//   int line_count;
// } buffer;

// void init_current_data(){
//   current_line = 0;
//   buffer.head = NULL;
//   buffer.tail = NULL;
//   buffer.line_count = 0;
// }

int create_node(Node * prev, Node * next, const char * line){
  Node * new_node = (Node *)malloc(sizeof(Node));
  new_node->line = strdup(line);
  new_node->next = next;
  new_node->prev = prev;
  buffer.line_count++;
  return 0;
}

int free_node(Node * node){
  if(node->prev) node->prev->next = node->next;
  if(node->next) node->next->prev = node->prev;
  if(buffer.head == node) buffer.head = node->next;
  buffer.line_count--;

  free(node->line);
  free(node);
  return 0;
}

int free_n_nodes(int first_line, int last_line){
  int n = (last_line - first_line) + 1;
  
  for(int i=1; i <= n; i++) {
    
  }
  return 0;
}

int print_nth_node(int n, Node * buffer_head){
  Node * node = buffer_head;
  for(int i=1; i<=n; i++){
    node = node->next;
  }
  printf("%s\n",node->line);
  return 0;
}
