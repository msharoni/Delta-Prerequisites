#include<iostream>
#include "exceptions.h"
using namespace std;

class Fraction{

    int numerator;
    int denominator;

    void setFraction(int _numerator, int _denominator){
        numerator = _numerator;
        denominator = _denominator;
    }

    public:
    Fraction(int _numerator, int _denominator){
        if(!_denominator)
            throw invalidInput("invalid denominator value");

        setFraction(_numerator, _denominator);            
    }

    int getNumerator(){
        return numerator;
    }

    int getDenominator(){
        return denominator;
    }

    friend ostream& operator<<(ostream& os, Fraction& _fraction){
        os << _fraction.getNumerator() << '/' << _fraction.getDenominator();
        return os;
    }

    Fraction operator+(Fraction other){

        return addOrSub("addition", other);
    }
    
    Fraction operator-(Fraction other){
        return addOrSub("subtraction", other);
    }
    Fraction operator*(Fraction other){
        int new_numerator = getNumerator() * other.getDenominator();
        int new_denominator = getDenominator() * other.getDenominator();
        return Fraction(new_numerator,new_denominator);
    }
    Fraction operator/(Fraction other){
        int new_numerator = getNumerator() * other.getDenominator();
        int new_denominator = getDenominator() * other.getNumerator();
        return Fraction(new_numerator,new_denominator);
    }
    bool operator==(Fraction other){
        return other.getNumerator() * getDenominator() == other.getDenominator() * getNumerator();
    }

    bool operator!=(Fraction other){
        return !(*this == other);
    }
    bool operator<(Fraction other){
        return getNumerator() * other.getDenominator() < getDenominator() * other.getDenominator();
    }
    bool operator>(Fraction other){
        return !(*this == other || *this < other);
    }
    bool operator>=(Fraction other){
        return !(*this < other);
    }
    bool operator<=(Fraction other){
        return !(*this > other);
    }
    operator double(){
        return double(getNumerator()/getDenominator());
    }
    operator float(){
        return float(getNumerator()/getDenominator());
    }
    //instead of writing the same code block twice (more readable)
    Fraction addOrSub(char* operation, Fraction _other){
        int new_numerator = 0;
        int numerator1 = getNumerator() * _other.getDenominator();
        int numerator2 = _other.getNumerator() * getDenominator();
        if(operation == "addition")
            new_numerator = numerator1 + numerator2;
        else if(operation == "subtraction")
            new_numerator = numerator1 - numerator2;
        int new_denominator = getDenominator() * _other.getDenominator();
        int GCD = findGCD(new_numerator, new_denominator);            
        Fraction ans = Fraction(new_numerator, new_denominator);
        ans.simplify();
        return ans;
    }

    //simplifies the fraction making it more readable and easier to operate upon
    void simplify(){
        int GCD = findGCD(getNumerator(),getDenominator());
        setFraction(getNumerator() / GCD, getDenominator() / GCD);
    }

    //Helps simplify the fraction by using the eucledian method to find gcd
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
