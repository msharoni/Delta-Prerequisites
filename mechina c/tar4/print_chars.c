#include<stdio.h>

int main(){

    //variable to hold amount and type of characters to print
    int chars_printed;
    char to_print;

    //prompt user and read input
    printf("Enter number of characters to print: ");
    scanf("%d",&chars_printed);

    //determine character to print based on given rules
    if(!(chars_printed % 2))
            to_print = '*';
    else if(!(chars_printed % 3))
        to_print = '^';
    else if(!(chars_printed % 5))
        to_print = '%';
    else
        to_print = '@'; 

    //print square of characters 
    for(int i=0;i<chars_printed;++i){
        for(int j=0;j<chars_printed;++j)
            printf("%c",to_print);
        printf("\n");
    }

    return 0;
}