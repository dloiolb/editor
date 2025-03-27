#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
// #include <readline/history.h>
#include "ed.h"
#include "node.h"
#include "commands.h"

// void file_numchars(){
//     FILE * file = fopen("abs.txt","r");
//     int count = 0;
//     char ch;
//     while ((ch = fgetc(file)) != EOF ){
//       count++;
//     }
//     printf("%d\n", count);
//     fclose(file);
// }

// extern Buffer ed_buffer;

int command_E(char * name){

    // set ed_filename
    if(strlen(name)<MAX_FILENAME_LENGTH){ 
        strcpy(ed_filename,name);
    }

    // load ed_buffer with each line of ed_filename
    FILE * file = fopen(ed_filename,"r");
    ed_buffer.line_count = 0;
    char buf[MAX_LINE_LENGTH];
    
    Node * temp;
    Node * temp2;
    if (fgets(buf, sizeof(buf), file)) {
        temp = create_node(NULL,NULL,buf);
    }
    while (fgets(buf, sizeof(buf), file)){
        temp2 = create_node(temp,NULL, buf);
        temp = temp2;
    }

    printf("%d\n", ed_buffer.line_count);
    fclose(file);

    return 0;
}

int command_a(){
    FILE * file = fopen(ed_filename, "");
}