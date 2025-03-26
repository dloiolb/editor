#include <stdlib.h>
// #include <readline/history.h>
#include "commands.h"

int command_E(char * name){
    // char * line = readline("");
    // printf("%s",name);
    if(strlen(name)<MAX_FILENAME_LENGTH){
        strcpy(filename,name);
    }
    // free(line);
    return 0;
}