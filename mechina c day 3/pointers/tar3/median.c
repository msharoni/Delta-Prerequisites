#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int count){
    for(int i = 0; i < count; ++i){
        for(int j = 0; j < count - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float get_median(int *arr, int count){
    float try = (arr[count/2 - 1] + arr[count/2]);
    return count % 2 == 0 ? (float)(arr[count/2 - 1] + arr[count/2]) / 2 : arr[count / 2];
}
int main() {
    int *arr = NULL;
    int input, count = 0;

    while (scanf("%d", &input) == 1) {
        arr = realloc(arr, (count + 1) * sizeof(int));
        arr[count++] = input;
    }
    
    bubble_sort(arr, count);
    printf("%f", get_median(arr, count));

    free(arr);
}