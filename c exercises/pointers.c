#include <stdio.h>
#include<stdlib.h>

#define SIZE 8
int main(){
    char* chars = malloc(SIZE  * sizeof(char));
    int* ints = malloc(SIZE  * sizeof(int));
    for(int i = 0; i < SIZE; ++i){
        scanf("%d", &ints[i]);
    }
    for(int i = 0; i < SIZE; ++i){
        scanf("%c", &chars[i]);
    }
    //using []
    for(int i = 0; i < SIZE; ++i){
        printf("%d", ints[i]);
    }
    for(int i = 0; i < SIZE; ++i){
        printf("%c", chars[i]);
    }

    //using *
    for(int i = 0; i < SIZE; ++i){
        printf("%d", *(ints + i));
    }
    for(int i = 0; i < SIZE; ++i){
        printf("%c", *(chars + i));
    }

    free(chars);
    free(ints);
    return 0;
}