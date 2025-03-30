#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ed.h"
#include "node.h"

Node * create_node(Node * prev, Node * next, const char * line){
  Node * new_node = (Node *)malloc(sizeof(Node));
  // if(ed_buffer_head == NULL) ed_buffer_head = new_node;
  new_node->line = strdup(line);
  new_node->next = next;
  new_node->prev = prev;

  // possibility to lose node
  if(new_node->prev) new_node->prev->next = new_node;
  if(new_node->next) new_node->next->prev = new_node;

  // ed_buffer.line_count++;
  return new_node;
}

Node * free_node(Node * node){
  if(node->prev) node->prev->next = node->next;
  if(node->next) node->next->prev = node->prev;
  if(ed_buffer_head == node) ed_buffer_head = node->next;
  // ed_buffer.line_count--;

  free(node->line);
  free(node);
  return 0;
}

Node * free_nodes_in_range(int n,int m){
  Node * temp;
  Node * temp2;
  temp = nth_node(n);
  Node * curr = temp->prev;
  int range = (m-n)+2;
  for (int i=1; i<range; i++){
    if (temp->next == NULL) break;
    temp2 = temp->next;
    free_node(temp);
    temp = temp2;
  }
  curr->next = temp;
  temp->prev = curr;
  return temp;
}

int free_all_nodes(){
  Node * temp;
  Node * temp2;
  temp = ed_buffer_head;
  while (temp != NULL){
      temp2 = temp->next;
      free_node(temp);
      temp = temp2;
  }
  return 0;
}

Node * nth_node(int n){
  Node * temp = ed_buffer_head;
  for (int i=1; i<n; i++){
    if (temp->next == NULL) break;
    temp = temp->next;
  }
  return temp;
}

int num_lines(){
  Node * temp = ed_buffer_head;
  int count = 0;
  while (temp != NULL){
    count++;
    temp = temp->next;
  }
  return count;
}

int num_chars(){
  Node * temp = ed_buffer_head;
  int count = 0;
  while (temp != NULL){
    count += strlen(temp->line);
    temp = temp->next;
  }
  return count;
}
