#include <stdio.h>
#include <stdlib.h>
#include "ed.h"
#include "node.h"

Node * create_node(Node * prev, Node * next, const char * line){
  Node * new_node = (Node *)malloc(sizeof(Node));
  // if(ed_buffer.head == NULL) ed_buffer.head = new_node;
  new_node->line = strdup(line);
  new_node->next = next;
  new_node->prev = prev;

  // possibility to lose node
  if(new_node->prev) new_node->prev->next = new_node;
  if(new_node->next) new_node->next->prev = new_node;

  ed_buffer.line_count++;
  return new_node;
}

int free_node(Node * node){
  if(node->prev) node->prev->next = node->next;
  if(node->next) node->next->prev = node->prev;
  if(ed_buffer.head == node) ed_buffer.head = node->next;
  ed_buffer.line_count--;

  free(node->line);
  free(node);
  return 0;
}

// int free_n_nodes(int first_line, int last_line){
//   int n = (last_line - first_line) + 1;
  
//   for(int i=1; i <= n; i++) {
    
//   }
//   return 0;
// }

// int print_nth_node(){
//   Node * node = ed_buffer.head;
//   for(int i=1; i<ed_currentline; i++){
//     node = node->next;
//   }
//   printf("%s\n",node->line);
  
//   return 0;
// }
