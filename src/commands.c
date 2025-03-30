#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

#include "ed.h"
#include "node.h"
#include "commands.h"

int most_recent_ERR;

typedef enum {
    ERR_MSG_1,
    ERR_MSG_2,
    ERR_MSG_3,
    ERR_COUNT  // Total number of errors
} ERRCode;

static const char *error_messages[ERR_COUNT] = {
    "Invalid address",
    "hm2",
    "hm3"
};

void command_E(char * name){

    // set ed_filename
    if(strlen(name)<MAX_FILENAME_LENGTH){ 
        strcpy(ed_filename,name);
    }
    else{
        printf("?\n");
        return;
    }

    // clear previous buffer
    free_all_nodes();

    // load ed_buffer with each line of ed_filename
    Node * temp;
    Node * temp2;
    FILE * file = fopen(ed_filename,"r");
    char buf[MAX_LINE_LENGTH];
    ed_buffer.head = NULL;
    if (fgets(buf, sizeof(buf), file)) {
        temp = create_node(NULL,NULL,buf);
        ed_buffer.head = temp;
    }
    while (fgets(buf, sizeof(buf), file)){
        temp2 = create_node(temp,NULL, buf);
        temp = temp2;
        ed_buffer.current = temp;
    }
    fclose(file);
    int chars = num_chars();
    printf("%d\n", chars);
}

void command_q(){
    exit(0);
}

void command_h(){
    printf("%s\n", error_messages[most_recent_ERR]);
}

void command_period(){
    printf("%s", ed_buffer.current->line);
}

void command_equal(){
    printf("%d\n", num_lines());
}

void command_w(){

    FILE * file = fopen(ed_filename,"w");
    
    Node * temp = ed_buffer.head;
    while (temp != NULL){
        fprintf(file, temp->line);
        temp = temp->next;
    }

    fclose(file);
}

void command_a(int n){
    if (n>=0) ed_buffer.current = nth_node(n);
    Node * temp = ed_buffer.current;
    while(1){
        char * line = readline("");
        if(strcmp(line,".")==0){
            free(line);
            break;
        }

        size_t len = strlen(line);
        line = realloc(line, len+2);
        line[len] = '\n';
        line[len+1] = '\0';

        if (temp == NULL){
            temp = create_node(NULL,NULL,line);
            ed_buffer.head = temp;
        }
        else{
            temp = create_node(temp, temp->next,line);
        }
        ed_buffer.current = temp;
        free(line);
    }

}

void command_c(){
}

void command_d(){
}

void command_e(){
    // FILE * file = fopen(ed_filename, "");
}

void command_f(){
    // FILE * file = fopen(ed_filename, "");
}

void command_H(){
    // FILE * file = fopen(ed_filename, "");
}