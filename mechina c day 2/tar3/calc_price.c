#include<stdio.h>

//global variables for price calculation
#define START_PRICE 5.5
#define PRICE_PER_KG 11
#define PRICE_PER_CM2 0.03
#define PRICE_PER_CMKG 0.01

int main(){

    //variables to hold parcel dimensions and weight
    int weight,len,width;

    //prompt user and read input
    printf("Enter weight (g), length (mm), width (mm): ");
    scanf("%d %d %d",&weight,&len,&width);

    //help placeholders for clear and concise code
    float cm2 = (len*width) / 100.0;
    float kg = weight / 1000.0;

    //calculate total price based on given formula
    float total_price = START_PRICE +
        kg * PRICE_PER_KG +
        cm2 * PRICE_PER_CM2 +
        cm2 / kg * PRICE_PER_CMKG;

    //print out parcel details and total price
    printf("parcel size cm^2: %.2f\n", cm2);
    printf("parcel weight kg: %.3f\n", kg);
    printf("Total price: %.2f₪ \n", total_price);
    
    return 0;
}