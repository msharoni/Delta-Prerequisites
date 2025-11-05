#include<iostream>
#include "Fraction.h"
using namespace std;
#define IS_TRUE(x,y) { if (x != y) cout << __FUNCTION__ << " failed on line " << __LINE__ << endl; }

//addition tests
void test_addtion(Fraction f1, Fraction f2, Fraction f3, Fraction f4){
    IS_TRUE(f1 + f2 , Fraction(7,6));
    IS_TRUE(f3 + f4 , Fraction(20,21));
    IS_TRUE(f1 + f3 , Fraction(11,14));
}

//subtraction tests
void test_subtraction(Fraction f1, Fraction f2, Fraction f3, Fraction f4){
    IS_TRUE(f1 - f2 , Fraction(-1,6));
    IS_TRUE(f3 - f4 , Fraction(-8,21));
    IS_TRUE(f1 - f3 , Fraction(3,14));
}

//multiplication tests
void test_multiplication(Fraction f1, Fraction f2, Fraction f3, Fraction f4){
    
    IS_TRUE(f1 * f2 , Fraction(1,3));
    IS_TRUE(f3 * f4 , Fraction(4,21));
    IS_TRUE(f1 * f3 , Fraction(1,7));
}

//divison tests
void test_division(Fraction f1, Fraction f2, Fraction f3, Fraction f4){
    IS_TRUE(f1 / f2 , Fraction(3,4));
    IS_TRUE(f3 / f4 , Fraction(3,7));
    IS_TRUE(f1 / f3 , Fraction(7,4));
}

//comparison operator tests
void test_comparisons(Fraction f1, Fraction f2, Fraction f3, Fraction f4){
    IS_TRUE(f1 == f2 , false);
    IS_TRUE(f1 != f3 , true);
    IS_TRUE(f1 < f4 , true);
    IS_TRUE(f2 <= f3 , false);
    IS_TRUE(f2 >= f4 , true);
    IS_TRUE(f3 > f4 , false);
}

void run_tests()
{
    Fraction f1(1,2), f2(2,3), f3(2,7), f4(80,120);
    test_addtion(f1,f2,f3,f4);
    test_subtraction(f1,f2,f3,f4);
    test_multiplication(f1,f2,f3,f4);
    test_division(f1,f2,f3,f4);
    test_comparisons(f1,f2,f3,f4);
}
