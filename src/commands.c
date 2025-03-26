#include <readline/history.h>
#include "../inc/commands.h"

int command_E(){
    char * line = readline("");
    free(line);
}