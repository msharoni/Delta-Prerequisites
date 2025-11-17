#include <stdio.h>

int main() {

    // Variables to hold current date and birth date
    int curr_year, curr_month, curr_day;
    int birth_year, birth_month, birth_day;

    // Prompt user for current date and birth date and read input
    printf("Enter current date: ");
    scanf("%d/%d/%d", &curr_day, &curr_month, &curr_year);
    printf("Enter Gary's birth date: ");
    scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);
    
    //arithmetic calculations to determine age in days, months, and years
    int age_days = (curr_year - birth_year) * 365 + (curr_month - birth_month) * 30 + (curr_day - birth_day);
    float age_months = age_days / 30.0;
    float age_years = age_days / 365.0;

    //print out Gary's age in days, months, and years
    printf("Gary's age in days: %d\n", age_days);
    printf("Gary's age in months: %f\n", age_months);
    printf("Gary's age in years: %f\n", age_years);
    return 0;
}