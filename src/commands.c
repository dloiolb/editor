#include <readline/history.h>
#include "commands.h"

int command_E(){
    char * line = readline("");
    free(line);
}