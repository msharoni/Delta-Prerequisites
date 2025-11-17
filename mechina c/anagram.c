/*------------------------------------------------------
* Filename: anagram_checker_to_implement.c
* Description: Main function for a program to check if two strings are anagrams
* Author: Segel Delta
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function prototype for isAnagram
int isAnagram(char str1[], char str2[]);

int main() {
    char str1[100], str2[100];

    // Get input strings from the user
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Check if the strings are anagrams
    if (isAnagram(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}

/* 
TODO: Implement the function isAnagram
The function should return 1 if str1 and str2 are anagrams, 0 otherwise.
*/
int isAnagram(char str1[], char str2[]) {

    int count[ALPHABET_SIZE] = {0};

    if (strlen(str1) != strlen(str2)) {
        return 0; 
    }
    for (int i = 0; str1[i] && str2[i]; i++) {
        count[str1[i] - 'a']++;
        count[str2[i] - 'a']--;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    return 1;
}

