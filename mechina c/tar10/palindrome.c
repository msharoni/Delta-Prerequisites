/*------------------------------------------------------
* Filename: palindrome_checker_to_implement.c
* Description: Program to check if a given string is a palindrome
* Author: Segel Delta
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

// Function prototype for isPalindrome
int isPalindrome(char str[]);

int main() {
    char str[100];

    // Get input string from the user
    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

/*
TODO: Implement the function isPalindrome
The function should return 1 if str is a palindrome, 0 otherwise.
*/
int isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}