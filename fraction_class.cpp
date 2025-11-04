#include "Fraction.h"

int main()
{
    try{
        Fraction fr = Fraction(2,10);
        Fraction fr1 = Fraction(1,5);
        fr = fr1 + fr;
        cout<<fr<<endl; 
        fr = fr - fr;
        cout<<fr<<endl;
        Fraction test = Fraction(10,0);
    
    }
    catch(invalidDenominator e){ cout<<e.what()<<endl; }
    return(0);
}