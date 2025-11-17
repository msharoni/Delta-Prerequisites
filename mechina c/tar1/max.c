#include <stdio.h>

int main() {
    int x = -2;
    int y = 0;
    int z = (x > y) * x + (x <= y) * y;


    printf("The maximum value is: %d\n", z);
    return 0;
}