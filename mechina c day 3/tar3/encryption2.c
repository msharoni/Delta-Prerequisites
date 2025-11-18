#include<stdio.h>
#include<string.h>

#define true 1

float avg(char arr[]){
    int sum = 0;
    for(int i = 0; i < strlen(arr); i++){
        sum += arr[i];
    }
    return (float)sum / strlen(arr);
}

void decrypt(char plan[], char password[]){

    int len = strlen(plan);
    //find average of ascii chars in password
    float average = avg(password);

    //remove average from each char in str
    for(int i = len - 4; i < len; i++){
        plan[i] = plan[i] - average;
    }

    char final_four[4] = {plan[len - 4], plan[len - 3], plan[len - 2], plan[len - 1]};
    if(strcmp(final_four, "safe")){
        printf("Decryption failed. Incorrect password.\n");
        return;
    }

    printf("Decrypted string: ");
    for(int i = 0; i < len - 4; i++){
        printf("%c" , (char)(plan[i] - average));
    }
    printf("\n");
    
    
}
int main(){

    //initialize variables
    char evil_plan[100];
    char password[100], confirm_password[100];

    // Prompt user and read input
    printf("Enter a your evil plans: ");
    scanf(" %[^\n]", evil_plan); 

    // Prompt user and read input for password
    while(true){
        printf("Create your password: ");
        scanf(" %[^\n]", &password);

        printf("Confirm your password: ");
        scanf(" %[^\n]", &confirm_password);

        if(!strcmp(password, confirm_password))
            break;
        printf("Passwords don't match. Try again.\n");
    }

    strcat(evil_plan, "safe");
    float average = avg(password);


    for(int i = 0; i < strlen(evil_plan); i++){
        evil_plan[i] = evil_plan[i] + average;
    }

    printf("your data is safe\n");

    while(true){
        printf("Enter password: ");
        scanf(" %[^\n]", password);
        decrypt(evil_plan, password);
    }

    return 0;
}