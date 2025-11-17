#include<stdio.h> 

int main(){

    int height;
    
    while(1){
        //prompt user and read input
        printf("Enter pyramid height (1-100): ");
        scanf("%d",&height);
        if(height >= 1 && height <= 100)
            break;
        printf("Invalid height. Please try again.\n");
    }

    for(int i=1;i<=height;++i){
        for(int j=0;j<height-i;++j)
            printf(" ");
        for(int k=0;k<2*i-1;++k)
            printf("#");
        printf("\n");   
    }

    return 0;
}