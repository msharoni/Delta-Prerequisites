#include <stdio.h>
#include <stdlib.h>

struct Time{
    int hour;
    int minute;
    int second;
};

void initTime(struct Time* time){
    printf("Enter hour: ");
    scanf("%d", &(time->hour));
    printf("Enter minute: ");
    scanf("%d", &(time->minute));
    printf("Enter second: ");
    scanf("%d", &(time->second));
}

struct Time* addTimes(struct Time* t1, struct Time* t2) {
    
    struct Time* result = malloc(sizeof(struct Time));

    //taking care of seconds
    result->second = t1->second + t2->second;
    int carry = result->second / 60;
    result->second %= 60;

    //taking care of minutes
    result->minute = t1->minute + t2->minute + carry;
    carry = result->minute / 60;
    result->minute %= 60;

    //taking care of hours
    result->hour = t1->hour + t2->hour + carry;
    result->hour %= 24;

    return result;
}


void printTime(struct Time* time){
    printf("%d:%d:%d\n", time -> hour, time -> minute, time -> second);
}
int main(){
    struct Time* time1 = malloc(sizeof(struct Time));
    struct Time* time2 = malloc(sizeof(struct Time));

    //initialize and print
    initTime(time1);
    initTime(time2);
    printTime(time1);
    printTime(time2);
    struct Time* time3 = addTimes(time1,time2);
    printTime(time3);

    //freeing heap data
    free(time1);
    free(time2);
    free(time3);

    return 0;
}
