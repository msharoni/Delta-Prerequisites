#include<stdio.h>
#include<stdlib.h>

#define size 8

void bracket_print_int(int *ptr){
    for(int i = 0; i < size; ++i){
        printf("val: %d\naddr: %p\n", ptr[i], &ptr[i]);
    }
}

void star_print_int(int *ptr){
    for(int i = 0; i < size; ++i){
        printf("val: %d\naddr: %p\n", *(ptr + i), (ptr + i));
    }
}

void bracket_print_char(char *ptr){
    for(int i = 0; i < size; ++i){
        printf("val: %c\naddr: %p\n", ptr[i], &ptr[i]);
    }
}

void star_print_char(char *ptr){
    for(int i = 0; i < size; ++i){
        printf("val: %c\naddr: %p\n", *(ptr + i), (ptr + i));
    }
}

int main(){
    int *int_arr = malloc(size * sizeof(int));
    char *char_arr = malloc(size * sizeof(char));
    
    printf("Enter %d integers:\n", size);
    for(int i = 0; i < size; ++i){
        scanf("%d", &int_arr[i]);
    }

    printf("Enter %d characters:\n", size);
    for(int i = 0; i < size; ++i){
        scanf(" %c", &char_arr[i]);
    }

    bracket_print_int(int_arr);
    star_print_int(int_arr);
    bracket_print_char(char_arr);
    star_print_char(char_arr);

    // free the allocated memory
    free(int_arr);
    free(char_arr);
    return 0;
}