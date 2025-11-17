#include<stdio.h>
#include<ctype.h>

#define COLA 5.2
#define DIET 7.2
#define ORANGE 3.4
#define SCHWEPPES 4.5
#define GRAPE 3.5
#define WATER 2.5

const float COINS[] = {0.1, 0.5, 1, 2, 5, 10};

enum Drinks{
    Cola = 'C',
    Diet = 'D',
    Orange = 'O',
    Schweppes = 'S',
    Grape = 'G',
    Water = 'W',
    Exit = 'E'
};

int get_money(){

    float total = 0;
    int input;
    
    for (int i = 0; i < sizeof(COINS); i++){
        printf("Enter amount  of %f", COINS[i]);
        scanf("%d", &input);
        total += input * COINS[i];
    }
    printf("The machine recieved payment of %.2f NIS", total);
    return total;
}

void get_change(float price, float money){

    float change_needed = money - price;
    for (int i = sizeof(COINS) - 1; i > 0; i--){
        int num_coins = change_needed / COINS[i];
  
        printf("Machine returned %d coins of %f NIS\n", num_coins, COINS[i]);
        change_needed -= num_coins * COINS[i];        
    }
    
}
int main(){
    char input;
    float money;
    int cola_coins[] = {0,0,0,0,0,0};

    printf("Enter drink choice (C,D,O,S,G,W): ");
    while(scanf("%c", input)){

        //entered incorrect input type (not char)
        if(!isalpha(input)){
            printf("Invalid Input! Try again: ");
            continue;
        }

        switch(input){
            case Cola:
                printf("The price of the drink is %d NIS\n",COLA);
                for (int i = 0; i < sizeof(COINS); i++){
                    prinf("Enter amount  of %f", COINS[i]);
                    scanf("%d", &input);
                    cola_coins[i] = input;
                    money += input * COINS[i];
                }

                printf("The machine recieved payment of %.2f NIS", money);

                if(cola_coins[0] == 1 && cola_coins[3] == 3 && cola_coins[4] == 3 && cola_coins[5] == 7){
                    printf("Hey agent enjoy your cola\n");
                }
                get_change(COLA, money);
                
                break;

            case Diet:
                printf("The price of the drink is %d NIS\n",DIET);
                money = get_money();
                get_change(DIET, money);
                break;

            case Orange:
                printf("The price of the drink is %d NIS\n",ORANGE);
                money = get_money();
                get_change(ORANGE, money);
                break;

            case Schweppes:
                printf("The price of the drink is %d NIS\n",SCHWEPPES);
                money = get_money();
                get_change(SCHWEPPES, money);
                break;

            case Grape:
                printf("The price of the drink is %d NIS\n",GRAPE);
                money = get_money();
                get_change(GRAPE, money);
                break;

            case Water:
                printf("The price of the drink is %d NIS\n",WATER);
                money = get_money();
                get_change(WATER, money);
                break;

            case Exit:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid Input! Try again: ");
                break;
        }
    }

    return 0;
}