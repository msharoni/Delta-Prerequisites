#include<stdio.h>

int get_nth(float a1, float q, int n){
    for(int i=1;i<n;++i){
        a1 *= q;
    }
    return a1;
}

int get_avg(float a1, float q, int n){
    float sum = 0;
    for (int i=0;i<n;++i){
        sum += a1;
        a1 *= q;
    }
    return sum / n;
}

int main(){
    float a1 , q;
    int n;

    //prompt user and read input
    printf("Enter a1,q,n: ");
    scanf("%f %f %d",&a1, &q, &n);

    //part a
    printf("Nth element: %d\n", get_nth(a1, q, n));

    //part b
    float avg = get_avg(a1, q, n);
    int bigger = 0;

    for (int i=0;i<n;++i){
        if(a1 > avg)
            bigger++;
        a1 *= q;
    }
    printf("Number of elements bigger than average: %d\n", bigger);
    return 0;
}