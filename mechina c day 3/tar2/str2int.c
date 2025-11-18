#include<stdio.h>
#include<stdlib.h>


int main(){

    //initialize string input
    char str[100];

    //prompt and read input
    printf("Enter a number:");
    scanf("%s", str);

    //convert string to int using func atoi() and add 36
    int result = atoi(str) + 36;
    
    printf("%d\n", result);
    return 0;
}