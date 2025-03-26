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
// #include "node.h"

#define BUFFER_SIZE 2048
#define MAX_TOKENS 20

//https://www.gnu.org/software/ed/manual/ed_manual.html

// global variables:
Buffer buffer; 
int current_line; // current line in buffer
char filename[MAX_FILENAME_LENGTH]; // current filename

void init_current_data(){
  current_line = 0;
  buffer.head = NULL;
  buffer.tail = NULL;
  buffer.line_count = 0;
}

void collect_tokens(char * line, char * arr[MAX_TOKENS], int * count);
void concatTokens(char * concatstring, char * arr[], int count);

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

void collect_tokens(char * line, char * arr[MAX_TOKENS], int * count){
    char * token = strtok(line, " ");
    int temp_count=0;
    while (token != NULL){
      arr[temp_count] = malloc(strlen(token));
      strcpy(arr[temp_count++],token);
      token = strtok(NULL, " ");
    }
    
    arr[temp_count] = NULL;
    *count = temp_count;
}

void concatTokens(char * concatstring, char * arr[], int count){
  concatstring[0] = '\0';
  for(int i=0;i<count;i++){
    if(arr[i] != NULL){
      strncat(concatstring, arr[i], BUFFER_SIZE - strlen(concatstring) -1);
      if(i < count-1 && arr[i+1] != NULL){
	strncat(concatstring, " ", BUFFER_SIZE - strlen(concatstring) -1);
      }
    }
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
    
    /*for(int i =0; i<=count;i++){
      printf("%d: %s\n",i,arr[i]);
    }*/
    
    /// 0000. ///
    if(strcmp(arr[0],"E")==0){
      if(count > 1 &&strcmp(arr[1],"abs.txt")==0){
	      file_numchars();	
      }
      else if(count > 1){
        command_E(arr[1]);
      }
      FILE * file = fopen("hi.txt","a+");
      fprintf(file,"ZZZZZ");
      fclose(file);
    }

    else if(strcmp(arr[0],"q")==0){
      exit(0);
    }

    else if(strcmp(arr[0],"name")==0){
      printf("%s\n",filename);
    }

    else{
      printf("?\n");
    }

    for (int i=0;i<count;i++){
      free(arr[i]);
    }
    
    free(line);

  }

  return 1;
}
