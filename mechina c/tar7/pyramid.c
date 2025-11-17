#include<stdio.h> 

#define true 1


int main(){

    int height;
    
    while(true){
        //prompt user and read input
        printf("Enter pyramid height (1-100): ");
        scanf("%d",&height);

        //check for validity
        if(height >= 1 && height <= 100)
            break;
        printf("Invalid height. Please try again.\n");
    }

    //print pyramid
    for(int i = 1; i <= height; ++i){
        for(int j = 0;j < height-i; ++j)
            //print spaces according to current row
            printf(" ");
        for(int k = 0; k < 2 * i - 1; ++k)
            //print hashes according to current row
            // the number of hashes is always odd and increases by 2 each row
            printf("#");
        printf("\n");   
    }

    return 0;
}