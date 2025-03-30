#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
//#include <signal.h>
#include <fcntl.h>
//#include <sys/wait.h>
#include "ed.h"
#include "node.h"
#include "commands.h"
#include "tokenize.h"

bool DEBUG_MODE = false;

// global variables:
Node * ed_buffer_head;
Node * ed_buffer_current;
char ed_filename[MAX_FILENAME_LENGTH]; // current ed_filename

void init_current_data(){
  ed_buffer_head = NULL;
  ed_buffer_current = NULL;
}

int get_num(char * line, int * i){
  int num = 0;
  while(1){
    if(line[*i] < '0' || line[*i] > '9'){
      return num;
    }
    int current_num = line[*i] - '0';
    num *= 10;
    num += current_num;
    (*i)++;
  }
  return num;
}

int read_command(char * line, char * arr[MAX_TOKENS], int count){

  // collect numbers if possible:

  int first_num = -1;
  int sec_num = -1;
  int index = 0;
  if( line[index] != '\0' && line[index] >= '0' && line[index] <= '9'){
    first_num = get_num(line, &index);
    if( line[index] == '\0'){}
    else if(line[index] == ','){
      index++;
      if(line[index] != '\0' && line[index] >= '0' && line[index] <= '9'){
        sec_num = get_num(line, &index);
      }
      else if( line[index] == '\0'){}
      else{
        error_msg();
        return 1;
      }
    }
  }

  if(line[index]=='\0'){
    if (sec_num >= 0){
      ed_buffer_current = nth_node(sec_num);
      command_period();
    }
    else if (first_num >= 0){
      ed_buffer_current = nth_node(first_num);
      command_period();
    }
  }

  // commands that don't take numbers:

  else if(strcmp(line,"E")==0){
    if(count > 1){
      command_E(arr[1]);
    }
  }

  else if(strcmp(line,"q")==0){
    command_q();
  }

  else if(strcmp(line,"h")==0){
    command_h();
  }

  else if(strcmp(line,".")==0){
    command_period();
  }

  else if(strcmp(line,"=")==0){
    command_equal();
  }

  else if(strcmp(line,"w")==0){
    if(count > 1){
      command_f(arr[1]);
    }
    command_w();
  }

  else if(strcmp(line,"f")==0){
    if(count > 1){
      command_f(arr[1]);
    }
  }

  // commands that take numbers:

  else if(line[index] == 'a'){
    if (sec_num >= 0) command_a(sec_num);
    else command_a(first_num);
  }

  else if(line[index] == 'c'){
    command_c(first_num,sec_num);
  }

  else if(line[index] == 'd'){
    command_d(first_num,sec_num);
  }

  // invalid commands:

  else{
    error_msg();
  }

}

int main(int argc, char *argv[]){

  init_current_data();
  if (argc > 1){
    command_E(argv[1]);
  }
  
  while (1){
    char * line = readline("");
    if(strcmp(line,"")==0){
      error_msg();
      continue;
    }
    // collect tokens from line 
    char * arr[MAX_TOKENS];
    int count = 0;
    collect_tokens(line, arr, &count);
    read_command(line, arr, count);

    for (int i=0;i<count;i++){
      free(arr[i]);
    }
    free(line);

  }
  return 1;
}
