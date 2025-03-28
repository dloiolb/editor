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
    FILE * file = fopen(ed_filename, "");
}

int command_c(){
    FILE * file = fopen(ed_filename, "");
}

int command_d(){
    FILE * file = fopen(ed_filename, "");
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
    Node * temp;
    Node * temp2;
    temp = ed_buffer.head;
    while (temp != NULL){
        temp2 = temp->next;
        free_node(temp);
        temp = temp2;
    }

    // load ed_buffer with each line of ed_filename
    FILE * file = fopen(ed_filename,"r");
    ed_buffer.line_count = 0;
    char buf[MAX_LINE_LENGTH];

    ed_buffer.head = NULL;
    if (fgets(buf, sizeof(buf), file)) {
        temp = create_node(NULL,NULL,buf);
        ed_buffer.head = temp;
    }
    while (fgets(buf, sizeof(buf), file)){
        temp2 = create_node(temp,NULL, buf);
        temp = temp2;
    }
    ed_currentline = ed_buffer.line_count;
    fclose(file);

    file = fopen(ed_filename, "r");
    int count = 0;
    while (fgetc(file) != EOF) { 
        count++;
    }
    fclose(file);
    ed_buffer.char_count = count;
    printf("%d\n", ed_buffer.char_count);

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
    Node * temp = ed_buffer.head;
    printf("%d\n", ed_currentline);
    if(ed_currentline > ed_buffer.line_count || ed_buffer.line_count == 0){
        printf("?\n");
        return 1;
    }

    // remake as Node * line_n(int n) in node.c ?
    for (int i=1; i<ed_currentline; i++){
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("%s", temp->line);
    return 0;
}

int command_equal(){
    printf("%d\n", ed_buffer.line_count);
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