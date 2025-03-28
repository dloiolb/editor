#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <unistd.h>
//#include <signal.h>
#include <fcntl.h>
//#include <sys/wait.h>
#include "ed.h"
#include "node.h"
#include "commands.h"
#include "tokenize.h"

//https://www.gnu.org/software/ed/manual/ed_manual.html

// global variables:
Buffer ed_buffer;
char ed_filename[MAX_FILENAME_LENGTH]; // current ed_filename

void init_current_data(){
  ed_buffer.head = NULL;
  ed_buffer.current = NULL;
}

void file_numchars(){
  FILE * file = fopen("abs.txt","r");
  int count = 0;
  char ch;
  while ((ch = fgetc(file)) != EOF ){
    count++;
  }
  printf("%d\n", count);
  fclose(file);
}

int read_command(char * arr[MAX_TOKENS], int count){
  // char * arr = *arr_ptr;
  // int count = *count_ptr;
  /// 0000. ///
  if(strcmp(arr[0],"E")==0){
    // if(count > 1 &&strcmp(arr[1],"abs.txt")==0){
    //   file_numchars();	
    // }
    if(count > 1){
      command_E(arr[1]);
    }
    // FILE * file = fopen("hi.txt","a+");
    // fprintf(file,"ZZZZZ");
    // fclose(file);
  }

  else if(strcmp(arr[0],"q")==0){
    exit(0);
  }

  else if(strcmp(arr[0],"h")==0){
    command_h();
  }
  else if(strcmp(arr[0],".")==0){
    command_period();
  }
  else if(strcmp(arr[0],"=")==0){
    command_equal();
  }

  else if(strcmp(arr[0],"name")==0){
    printf("%s\n",ed_filename);
  }

  else{
    printf("?\n");
  }
}

int main(int argc, char *argv[]){
  init_current_data();
  
  while (1){
    char * line = readline("");
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
    
    read_command(arr, count);

    for (int i=0;i<count;i++){
      free(arr[i]);
    }
    
    free(line);

  }

  return 1;
}
