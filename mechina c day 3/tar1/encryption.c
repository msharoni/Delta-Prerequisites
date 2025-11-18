#include<stdio.h>
#include<stdlib.h>

#define chars 26

const int test[] = {
    921, 842, 884, 953, 834, 837, 914, 915,
    936, 948, 864, 780, 542, 116, 928, 925,
    372, 365, 911, 909, 937, 959, 945, 940,
    891, 886};

const int gargamel_answer[26] = {
    957, 974, 890, 885, 857, 862, 960, 877,
    758, 840, 931, 850, 619, 116, 921, 911,
    365, 375, 865, 786, 919, 998, 970, 973,
    378, 362
};

void flip_n_print(int *arr){
    for(int i = chars * 1.5; i >= 0; --i)
        printf("%c", (char)arr[i % chars]);
    printf("\n");
}

void move(int arr[], int steps){
    int temp[chars] = {0};
    for(int i = 0; i < chars; ++i)
        temp[(i + steps) % chars] = arr[i];
    for(int i = 0; i < chars; ++i)
        arr[i] = temp[i];
    
}

void encrypt(){

    // plaintext must be exactly 26 chars long
    char plain_text[chars + 1] = "None of your business bro!";
    int arr[chars];

    //step 1: convert chars to ints
    for(int i = 0; i < chars; ++i)
        arr[i] = (int)plain_text[i];

    //step 2: add 5 to every value
    for(int i = 0; i < chars; ++i)
        arr[i] += 5;

    //step 3: move all chars forward 4 times
    move(arr, 4);

    //step 4: multiply every even index by 7
    for(int i = 0; i < chars; ++i)
        if (i % 2 == 0)
            arr[i] *= 7;

    //step 5: move all chars forward chars - 5 times (effectively backwards 5 times)
    move(arr, chars - 5);

    // step 6: add previous value to current value for each value except first
    for(int i = chars - 1; i > 0; --i)
        arr[i] += arr[i - 1];

    //step 7: move all chars forward chars / 2 times
    move(arr, chars / 2);

    // print the encrypted ints in initializer form
    for(int i = 0; i < chars; ++i){
        printf("%d ", arr[i]);
    }
    
}

void sub_prev(int *arr){
    for(int i =  1; i < chars; ++i)
        arr[i] -= arr[i - 1];
}

void copy_arr(const int src[], int dest[]){
    for(int i = 0; i < chars; ++i)
        dest[i] = src[i];
}
int main(){

    //encrypt();

    //copy a example encrypted array
    int arr[chars];
    copy_arr(gargamel_answer, arr);
    
    //step 1: push all chars up chars/2 times
    //this effectively splits the array in half and swaps the two halves
    move(arr, chars / 2);

    //step 2: subtract previous value from current value for each value except first
    sub_prev(arr);

    //step 3: move all chars forward 5 times
    move(arr, 5);

    //step 4: divide every even index by 7
    for(int i = 0; i < chars; ++i){
        if(i % 2 == 0)
            arr[i] /= 7;
    }

    //step 5: move all chars forward chars - 4 times (effectively backwards 4 times)
    move(arr, chars - 4);

    //step 6: subtract 5 from every value
    for(int i = 0; i < chars; ++i){
        arr[i] -= 5;
    }

    //step 7: convert and print the result
    for(int i = 0; i < chars; ++i)
        printf("%c", (char)arr[i]);

    return 0;
}