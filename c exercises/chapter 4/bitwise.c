#include<stdio.h>
#include<stdbool.h>

bool isEven(int num){
    return (num & 1) == 0;
}

int cycleBitsLeft(int num, int n){
    return (num << n) | (num >> (sizeof(num)*8 - n));
}

int main(){
    int number = 18;
    printf("Is Even: %s\n", isEven(number) ? "true" : "false");
    printf("Cycle Bits Left by 2: %d\n", cycleBitsLeft(number, 2));
    return 0;
}
