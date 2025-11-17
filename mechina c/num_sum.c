#include<stdio.h>

int main(){

    int num, sum_edges, sum_middle = 0;

    scanf("%d",&num);
    sum_edges = num;
    //prompt user and read input
    while(scanf("%d",&num))
        sum_middle += num;
    sum_middle -= num;
    sum_edges += num;
    sum_edges == sum_middle ? printf("The sum is equal.") : printf("The sum is not equal."); 

    return 0;
}