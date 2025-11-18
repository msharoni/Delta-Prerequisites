#include<stdio.h>
#include<stdlib.h>

#define size 8

void bubble_sort(int **arr){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(*arr[j] > *arr[j + 1]){
                int *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int int_arr[size];
    int **pointer_arr = malloc(size * sizeof(int*));
    
    // prompt and get input
    printf("Enter %d integers:\n", size);
    for(int i = 0; i < size; ++i){
        scanf("%d", &int_arr[i]);
    }

    // fill the pointer array
    for(int i = 0; i < size; ++i){
        pointer_arr[i] = &int_arr[i];
    }

    // print the pointer array b4 sort
    for(int i = 0; i < size; ++i){
        printf("val: %d\naddr: %p\n", *(pointer_arr[i]), pointer_arr[i]);
    }

    bubble_sort(pointer_arr);

    // print the pointer array after sort
    for(int i = 0; i < size; ++i){
        printf("val: %d\naddr: %p\n", *(pointer_arr[i]), pointer_arr[i]);
    }
    
    // free the allocated memory
    free(pointer_arr);

    return 0;
}