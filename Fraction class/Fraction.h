#include<iostream>
#include "exceptions.h"
using namespace std;

class Fraction{

    int nominator;
    int denominator;

    void setFraction(int _nominator, int _denominator){
        nominator = _nominator;
        denominator = _denominator;
    }

    public:
    Fraction(int _nominator, int _denominator){
        if(!_denominator)
            throw invalidDenominator("invalid denominator value");

        setFraction(_nominator, _denominator);            
    }

    int getNominator(){
        return nominator;
    }

    int getDenominator(){
        return denominator;
    }

    friend ostream& operator<<(ostream& os, Fraction& _fraction){
        os << _fraction.getNominator() << '/' << _fraction.getDenominator();
        return os;
    }

    Fraction operator+(Fraction other){

        return addOrSub("addition", other);
    }
    
    Fraction operator-(Fraction other){
        return addOrSub("subtraction", other);
    }
    Fraction operator*(Fraction other){
        int new_nominator = getNominator() * other.getDenominator();
        int new_denominator = getDenominator() * other.getDenominator();
        return Fraction(new_nominator,new_denominator);
    }
    Fraction operator/(Fraction other){
        int new_nominator = getNominator() * other.getDenominator();
        int new_denominator = getDenominator() * other.getNominator();
        return Fraction(new_nominator,new_denominator);
    }
    bool operator==(Fraction other){

    }

    //instead of writing the same code block twice (more readable)
    Fraction addOrSub(char* operation, Fraction _other){
        int new_nominator = 0;
        int nominator1 = getNominator() * _other.getDenominator();
        int nominator2 = _other.getNominator() * getDenominator();
        if(operation == "addition")
            new_nominator = nominator1 + nominator2;
        else if(operation == "subtraction")
            new_nominator = nominator1 - nominator2;
        int new_denominator = getDenominator() * _other.getDenominator();
        int GCD = findGCD(new_nominator, new_denominator);            
        Fraction ans = Fraction(new_nominator/GCD, new_denominator/GCD);
        return ans;
    }
    //Helps simplify the fraction after adding or subtracting
    int findGCD(int num1, int num2){

        int help = num2;
        while(num2){
            help = num2;
            num2 = num1 % num2;
            num1 = help;
        }
        return help;
    }
};
