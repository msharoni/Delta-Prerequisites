#include<stdio.h>

void addition(int a, int b) {
    printf("Result: %d\n", a + b);
}

void subtraction(int a, int b) {
    printf("Result: %d\n", a - b);
}

void multiplication(int a, int b) {
    printf("Result: %d\n", a * b);
}

void division(int a, int b) {
    if (b != 0)
        printf("Result: %.2f\n", (float)a / b);
    else
        printf("ERROR! Division by zero.\n");
}

void expponent(int a, int b) {
    int result = 1;
    for(int i = 0; i < b; i++) {
        result *= a;
    }
    printf("Result: %d\n", result);
}

void modulus(int a, int b) {
    if (b != 0)
        printf("Result: %d\n", a % b);
    else
        printf("ERROR! Modulus by zero.\n");
}

int main(){

    int num1, num2;
    char operator;

    printf("Enter first number: ");

    while(1){
        if(scanf("%d", &num1))
            break;
        else {
            printf("Invalid input. Please enter a number");
            while(getchar() != '\n');}
    }
    
    
    printf("Enter an operator: ");
    while(1){
        if(scanf(" %c", &operator) && (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^' || operator == '%'))
            break;
        else {
            printf("Invalid input. Please enter a valid operator.");
            while(getchar() != '\n');}
    }
    printf("Enter second number: ");
    while(1){
        if(scanf("%d", &num2))
            break;
        else {
            printf("Invalid input. Please enter a number");
            while(getchar() != '\n');}
    }

    switch(operator){
        case '+':
            addition(num1, num2);
            break;
        case '-':
            subtraction(num1, num2);
            break;
        case '*':
            multiplication(num1, num2);
            break;
        case '/':
            division(num1, num2);
            break;
        case '^': 
            expponent(num1, num2);
            break;
        case '%':
            modulus(num1, num2);
            break;
        default:
            printf("Invalid operator.\n");
    }

    return 0;
}