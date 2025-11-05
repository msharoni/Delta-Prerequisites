#include "tests.h"
int main()
{
    try{
        Fraction fr = Fraction(2,10);
        Fraction fr1 = Fraction(1,5);
        fr = fr1 + fr;
        cout<<fr<<endl; 
        fr = fr - fr - fr;
        //fr = Fraction(800,840);
        //fr.simplify();
        cout<<fr<<endl;
        //Fraction test = Fraction(10,0);
        if(fr != fr){
            cout<<"hi"<<endl;
        }
        run_tests();
    
    }
    catch(invalidInput e){ cout<<e.what()<<endl; }
    return(0);
}
