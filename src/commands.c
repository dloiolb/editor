#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
// #include <readline/history.h>
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

int command_a(){
    char * line = readline("");
    while(strcmp(line,".")!=0){
        // createline
        char * line = readline("");
    }
}

int command_c(){
}

int command_d(){
}

int command_e(){
    FILE * file = fopen(ed_filename, "");
}


int command_E(char * name){

    // set ed_filename
    if(strlen(name)<MAX_FILENAME_LENGTH){ 
        strcpy(ed_filename,name);
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

    return 0;
}

int command_f(){
    FILE * file = fopen(ed_filename, "");
}

int command_h(){
    printf("%s\n", error_messages[most_recent_ERR]);
}

int command_H(){
    FILE * file = fopen(ed_filename, "");
}

int command_period(){

    printf("%s", ed_buffer.current->line);
    return 0;
}

int command_equal(){
    printf("%d\n", num_lines());
}

int command_w(){

    FILE * file = fopen(ed_filename,"w");
    
    Node * temp = ed_buffer.head;
    while (temp != NULL){
        fprintf(file, temp->line);
        temp = temp->next;
    }

    fclose(file);

    return 0;
}