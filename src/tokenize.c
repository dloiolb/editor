#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "tokenize.h"

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