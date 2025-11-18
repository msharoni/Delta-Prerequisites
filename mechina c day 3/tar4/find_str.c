#include<stdio.h>
#include<string.h>

const char source_str[] = "I belive wholeheartedly that Mor Sharoni deserves 100%%!";
const char target_str[] = "Mor Sharoni";

void find_str(const char source[], const char target[]){
    
    int cur_target_index = 0;
    int target_length = strlen(target);

    //search for target in source
    for(int i = 0; i < strlen(source); ++i){
        //if mathch found increment target index
        if(source[i] == target[cur_target_index]){
            cur_target_index++;
            //if full target found print index and return
            if(cur_target_index == target_length - 1){
                printf("Found at index %d\n", i - target_length + 2);
                return;
            }
        //if no match reset target index
        } else {
            cur_target_index = 0;
        }
    }
    printf("Not found.\n");
}

int main(){

    find_str(source_str, target_str);
    return 0;
}