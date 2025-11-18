#include<stdio.h>
#include<string.h>

#define true 1
#define false 0

int balance(char* str){
    int spaces = 0, words = 0;
    int prev_was_char = false;
    
    // get the count of words and count of spaces
    char temp[strlen(str)]; 
    for (int i = 0; i < strlen(str); i++){
        if(str[i] == ' '){
            spaces++;
            if(prev_was_char){
                words++;
                prev_was_char = false;
            }
        }else{
            prev_was_char = true;
        }
    }

    // increment for last word if needed
    prev_was_char ? words++ : 0;

    // make sure that spaces can be split evenly between words
    if(spaces % (words - 1))
        return false;
    
    int word_index = 0;
    prev_was_char = false;

    // loop through str and save a str that has even spacing in temp
    for (int i = 0; i < strlen(str); i++){
        //add chars
        if(str[i] != ' '){
            temp[word_index] = str[i];
            word_index++;
            prev_was_char = true;
        }
        // if temp is full print & exit
        else if(word_index == strlen(str)){
            printf("%s\n", temp);
            return true;
        }
        //add spaces
        else if(prev_was_char){
            for (int j = 0; j < spaces/(words - 1); j++){
                temp[word_index] = ' ';
                word_index++;
            }
            prev_was_char = false;
        }
    }
}

int main(){

    char str1[] = " try this k   ";
    
    balance(str1);

    return 0;
}