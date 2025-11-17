#include<stdio.h>

int main(){

    //variable to hold amount and type of characters to print
    int num_printed;
    char char_to_print;

    //prompt user and read input
    printf("Enter number of characters to print: ");
    
    while(scanf("%d",&num_printed) != 1 || num_printed <= 0){
        printf("Invalid input. Try again: ");

        //clear invalid input in buffer
        while(getchar() != '\n');
    }

    //determine character to print based on given rules
    if(!(num_printed % 2))
            char_to_print = '*';
    else if(!(num_printed % 3))
        char_to_print = '^';
    else if(!(num_printed % 5))
        char_to_print = '%';
    else
        char_to_print = '@'; 

    //print square of characters 
    for(int i=0;i<num_printed;++i){
        for(int j=0;j<num_printed;++j)
            printf("%c",char_to_print);
        printf("\n");
    }

    return 0;
}