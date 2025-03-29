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
Buffer ed_buffer;
char ed_filename[MAX_FILENAME_LENGTH]; // current ed_filename

void init_current_data(){
  ed_buffer.head = NULL;
  ed_buffer.current = NULL;
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
      else{
        printf("?\n");
        return;
      }
    }
    else{
      printf("?\n");
      return;
    }
  }

  if(line[index]=='\0'){
    if (sec_num >= 0){
      ed_buffer.current = nth_node(sec_num);
      command_period();
    }
    else if (first_num >= 0){
      ed_buffer.current = nth_node(first_num);
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
    exit(0);
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
    command_w();
  }

  // commands that take numbers:

  else if(line[index] == 'a'){
    command_a(first_num);
  }

  // invalid commands:

  else{
    printf("?\n");
  }

}

int main(int argc, char *argv[]){

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-debug") == 0) {
      DEBUG_MODE = true;
      break;
    }
  }
  
  init_current_data();
  
  while (1){
    char * line = readline("");
    if (DEBUG_MODE) printf("\033[A\033[K");
    if(strcmp(line,"")==0){
      printf("?\n");
      continue;
    }
    // collect tokens from line 
    char * arr[MAX_TOKENS];
    int count = 0;
    collect_tokens(line, arr, &count);
    
    // for(int i =0; i<=count;i++){
    //   printf("%d: %s\n",i,arr[i]);
    // }
    
    read_command(line, arr, count);

    for (int i=0;i<count;i++){
      free(arr[i]);
    }
    
    free(line);

  }

  return 1;
}
