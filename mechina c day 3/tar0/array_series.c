#include<stdio.h>
#include<stdlib.h>


int main(){

    //intialize array using malloc
    int *arr1 = malloc(15 * sizeof(int));
    int greater = 1, less = 1, equal = 1;

    //fill array with values
    for(int i = 0; i < 15; ++i){
        scanf("%d",&arr1[i]);
        
        //for each value except the first compare it to the previous value
        if(i > 0){
            greater = greater && (arr1[i] > arr1[i-1]);
            less = less && (arr1[i] < arr1[i-1]);
            equal = equal && (arr1[i] == arr1[i-1]);
        }
    }

    //print result based on comparison results
    greater ? printf("The array is increasing\n") :
    less ? printf("The array is decreasing\n") : equal ? printf("The array is constant\n") : printf("The array is messed up\n");
    return 0;
}