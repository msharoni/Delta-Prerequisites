#include<stdio.h>
#include<stdbool.h>


const char* base = 
"###  ###  ###  ###  ###  ###  ###  ###\n"
"###  ###  ###  ###  ###  ###  ###  ###\n"
"###  ###  ###  ###  ###  ###  ###  ###\n"
"###  ###  ###  ###  ###  ###  ###  ###\n"
"######################################\n"
"                   ||                 \n"
"                   ||                 \n"
"                   ||                 \n"
"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

const char *candles = "#    #    #    #    #    #    #    #    ";

//the function below prints a hanukia using loops and conditionals
//the conditions in the excersise were unclear regarding the use of loops so the function is commented out
//the easier way to print the hanukia is by using a string as shown above so I left both implementations
/*
void print_hanukia(){
    bool not_space = true;
    for(int i=0;i<9;++i){
        for(int j=0;j<38;++j){
            if(i < 4)
                if(not_space){
                    printf("###");
                    j += 2;
                    not_space = j == 37;
                }else{
                    printf("  ");
                    j++;
                    not_space = true;
                }
            else if(i == 4)
                printf("#");
            else if(i < 8 && i > 4)  
                if(j == 19 || j == 20)  
                    printf("|");
                else
                    printf(" ");
            else
                printf("^");
            

        }
        printf("\n");
    }
}
*/

int main(){

    int numDays;

    //prompt user and read input
    printf("Enter number of days Hanukkah lasts (from 1 to 8): ");
    scanf("%d",&numDays);

    //print the hanukia's candles based on user input
    printf(" ");
    printf("%.*s\n", numDays * 5, candles);
    printf("%s\n",base);

    //print_hanukia();
    return 0;
}