#include<stdio.h>
#include<stdlib.h>


// Dont know how to do this. 
// I tried my best.

int main(){
    const  int channel = 10;

    int new_channel;
    printf("Enter new channel: ");
    scanf("%d", &new_channel);
    
    const int *help = &channel;
    help = &new_channel;

    printf("new channel is: %d\n", channel);

    return 0;
}