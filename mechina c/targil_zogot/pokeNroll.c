#include<stdio.h>
#include<ctype.h>
#include <math.h>

#define COLA 5.2
#define DIET 7.2
#define ORANGE 3.4
#define SCHWEPPES 4.5
#define GRAPE 3.5
#define WATER 2.5
#define HEIGHT 1.5
#define PI 3.14159

const float COINS[] = {0.1, 0.5, 1, 2, 5, 10};
const int DRINK_SPEEDS[] = {20, 20, 20, 10, 5, 5};

enum Drinks{
    Cola = 'C',
    Diet = 'D',
    Orange = 'O',
    Schweppes = 'S',
    Grape = 'G',
    Water = 'W',
    Exit = 'E'
};

enum DrinkSpeeds{
    ColaSpeed = 20,
    DietSpeed = 20,
    OrangeSpeed = 20,
    SchweppesSpeed = 10,
    GrapeSpeed = 5,
    WaterSpeed = 5
};

int get_money(){

    float total = 0;
    int input;

    for (int i = 0; i < sizeof(COINS)/sizeof(float); i++){
        printf("Enter amount  of %f ", COINS[i]);
        scanf("%d", &input);
        total += input * COINS[i];
    }
    printf("The machine recieved payment of %.2f NIS \n", total);
    return total;
}

void get_change(float price, float money){

    float change_needed = money - price;
    for (int i = sizeof(COINS)/sizeof(float); i > 0; i--){
        int num_coins = change_needed / COINS[i - 1];

        printf("Machine returned %d coins of %f NIS\n", num_coins, COINS[i-1]);
        change_needed -= num_coins * COINS[i-1];
    }
}

float calc_speed(float speed_payed, int base_speed){    
    return  speed_payed * 5 + base_speed;
}

float calc_distance(float speed ){
    float angle = PI / 4;
    float v0x = speed * cos(angle);
    float v0y = speed * sin(angle);

    float disc = (v0y * v0y) + (2 * 9.81 * 1.5);
    disc = sqrt(disc);

    float time = (v0y + disc) / 9.81;
    return v0x * time;
}

int main(){
    char input;
    float money,speed_money;
    float drink_speed;
    int cola_coins[] = {0,0,0,0,0,0};

    printf("Enter drink choice (C,D,O,S,G,W,E): ");
    while(scanf(" %c", &input)){

        input = toupper(input);
        //entered incorrect input type (not char)
        if(!isalpha(input)){
            printf("Invalid Input! Try again: ");
            continue;
        }

        switch(input){
            case Cola:
                printf("The price of the drink is %f NIS\n", COLA);
                printf("Please choose the launching cost of the drink, in NIS\n");
                scanf("%f", &speed_money);

                drink_speed = calc_speed(speed_money, ColaSpeed);

                printf("The drink velocity will be %f meters per second\n", drink_speed);
                for (int i = 0; i < sizeof(COINS)/sizeof(float); i++){
                    printf("Enter amount  of %f ", COINS[i]);
                    scanf("%d", &cola_coins[i]);
                    money += cola_coins[i] * COINS[i];
                }

                printf("The machine recieved payment of %.2f NIS\n", money);

                if(cola_coins[0] == 1 && cola_coins[3] == 3 && cola_coins[4] == 3 && cola_coins[5] == 7){
                    printf("Hey agent enjoy your cola\n");
                }

                get_change(COLA + speed_money, money);
                printf("The drink will travel %f meters\n", calc_distance(drink_speed));
                break;

            case Diet:
                printf("The price of the drink is %f NIS\n",DIET);

                printf("Please choose the launching cost of the drink, in NIS\n");
                scanf("%f", &speed_money);
                drink_speed = calc_speed(speed_money, DietSpeed);

                money = get_money();

                get_change(DIET + speed_money, money);

                printf("The drink will travel %f meters\n", calc_distance(drink_speed));
                break;

            case Orange:
                printf("The price of the drink is %f NIS\n",ORANGE);
                printf("Please choose the launching cost of the drink, in NIS\n");
                scanf("%f", &speed_money);
                drink_speed = calc_speed(speed_money, OrangeSpeed);

                money = get_money();

                get_change(ORANGE + speed_money, money);

                printf("The drink will travel %f meters\n", calc_distance(drink_speed));
                break;

            case Schweppes:
                printf("The price of the drink is %f NIS\n",SCHWEPPES);
                printf("Please choose the launching cost of the drink, in NIS\n");
                scanf("%f", &speed_money);
                drink_speed = calc_speed(speed_money, SchweppesSpeed);

                money = get_money();
                get_change(SCHWEPPES + speed_money, money);
                printf("The drink will travel %f meters\n", calc_distance(drink_speed));
                break;

            case Grape:
                printf("The price of the drink is %f NIS\n",GRAPE);
                printf("Please choose the launching cost of the drink, in NIS\n");
                scanf("%f", &speed_money);
                drink_speed = calc_speed(speed_money, GrapeSpeed);

                money = get_money();
                get_change(GRAPE + speed_money, money);
                printf("The drink will travel %f meters\n", calc_distance(drink_speed));
                break;

            case Water:
                printf("The price of the drink is %f NIS\n",WATER);
                printf("Please choose the launching cost of the drink, in NIS\n");
                scanf("%f", &speed_money);
                drink_speed = calc_speed(speed_money, WaterSpeed);
                money = get_money();
                get_change(WATER + speed_money, money);
                printf("The drink will travel %f meters\n", calc_distance(drink_speed));
                break;

            case Exit:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid Input! Try again: ");
                break;
        }
        printf("Enter drink choice (C,D,O,S,G,W,E): ");
    }

    return 0;
}