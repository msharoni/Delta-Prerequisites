#include "Drink.h"
#include <limits>
#include <cstdlib> 
#include <ctime> 

enum DrinkType{
    wine,
    beer
};

enum WineType{
    carmelEmeraldRazling,
    golanSmadar,
    yardenSherdona,
    keanti,
    yardenHarChermonAdom,
    yardenKavernaSovinion,
    chateauMargot
};   

enum BeerType{
    heineken,
    goldstar,
    maccabi,
    tuborg
};

//tried using files to maybe make the data insertion more seamless      
/*
//initialize the bars _stock
Drink* create_bar(string drinks_file){
    int numOfDrinks = 0;

    ifstream file(drinks_file);
    string str;
    while (getline(file, str)){
        numOfDrinks++;
    }

    ifstream file(drinks_file);

    /*Drink* _stock = new Drink[numOfDrinks];
    for(int i = 0; i < numOfDrinks; ++i){
        ifstream file(drinks_file, str);
        
        _stock[i] = Drink(str);
    }
    
    Drink* _stock = new Drink[numOfDrinks];
    return _stock;
    
}

Drink Decypher(string str){
        for (char c : str) {
        if (c == ' ') {
          
            // If a space is found, add the word to the vector
            words.push_back(word);
          
            // Reset the word
            word = "";
        }
        else {
            // Append the character to the current word
            word += c;
        }
    }
    }
*/

int get_rand(int delta, int start = 0){
    return start + rand() % delta;
}

Drink** initialize_stock(int &numOfDrinks){
    srand(time(0));
    numOfDrinks = 3 + rand() % 10; 

    Drink** _stock = new Drink*[numOfDrinks];

    //given values to start off the dynamic array
    _stock[0] = new CarmelEmeraldRazling(1986, get_rand(18,3));
    _stock[1] = new GolanSmadar(1989, get_rand(18,3));
    _stock[2] = new YardenHarChermonAdom(1994, get_rand(18,3));
    

    //simulate some random values to fill out the bar

    for(int i=0; i < numOfDrinks - 3; ++i){
        
        switch(get_rand(2)){
            case beer:
                switch(get_rand(4)){
                    case heineken:
                        _stock[i + 3] = new Heineken(get_rand(4,4));
                        break;
                    case goldstar:
                        _stock[i + 3] = new Goldstar(get_rand(4,4));
                        break;
                    case maccabi:
                        _stock[i + 3] = new Maccabi(get_rand(4,4));
                        break;
                    case tuborg:
                        _stock[i + 3] = new Tuborg(get_rand(4,4));
                        break;
                }
                break;

            case wine:
                switch (get_rand(7)){
                    case carmelEmeraldRazling:
                        _stock[i + 3] = new CarmelEmeraldRazling(1970, get_rand(18,3));
                        break;
                    case golanSmadar:
                        _stock[i + 3] = new GolanSmadar(1970, get_rand(18,3));
                        break;
                    case yardenSherdona:
                        _stock[i + 3] = new YardenSherdona(1970, get_rand(18,3));
                        break;
                    case keanti:
                        _stock[i + 3] = new Keanti(1970, get_rand(18,3));
                        break;
                    case yardenHarChermonAdom:
                        _stock[i + 3] = new YardenHarChermonAdom(1970, get_rand(18,3));
                        break;
                    case yardenKavernaSovinion:
                        _stock[i + 3] = new YardenKavernaSovinion(1970, get_rand(18,3));
                        break;
                    case chateauMargot:
                        _stock[i + 3] = new ChateauMargot(1970, get_rand(18,3));
                        break;
                }
                break;
        }
    }

    return _stock;
}
int main(){

    //initialize bars stock using given objects and random created ones
    int numOfDrinks = 0;
    Drink** stock = initialize_stock(numOfDrinks);

    //create a list of the drinks that the customer has ordered
    int numOfCustomerDrinks = 0;    
    Drink** customerDrinks = new Drink*[numOfDrinks];

    //the actual program loop
    int userChoice = 0;
    while(int(userChoice) != 100){
        cout<< "What can I get you, sir? (0 - list options)" << endl;
        cin >> userChoice;
        if (cin.fail()) {
            cout << "Invalid input! Expected an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            userChoice = -1;
        }
        
        switch (userChoice)
        {
        case 0:
            for(int i = 0; i < numOfDrinks; ++i) {
                cout<< i + 1 << ' ' << stock[i]->getName() << endl;
            }
            cout << "99 Prepare last drink." << endl;
            cout << "100 Close the bar." << endl;
            break;
        
        case 99:
            if(numOfCustomerDrinks > 0){
                //prepare the last ordered drink
                customerDrinks[numOfCustomerDrinks - 1] -> prepare();
                //remove it from thth customerDrinks list
                customerDrinks[--numOfCustomerDrinks] = nullptr;
            }else
                cout << "No drinks ordered yet!" << endl;
            break;

        case 100:
            break;

        case -1:
            //invalid input already handled (-1 is just placeholder)
            break;

        default:
            if(userChoice <= numOfDrinks && userChoice > 0){
                int currDrink = userChoice - 1;
                //print the wanted dialect
                cout << "One " << stock[currDrink] -> getName() << " coming up, sir." << endl;
                //move ownership of pointer from stock to customerDrinks
                customerDrinks[numOfCustomerDrinks++] = stock[currDrink];
                //safely remove the drink from stock
                for(int i =  currDrink; i <  numOfDrinks; ++i){
                    stock[i] = stock[i + 1];
                }
                numOfDrinks--;
            }
            else
                cout << "Invalid input! Try again." << endl;
            break;
        }

    }


    cout<<"Bar is closed. Good night"<<endl;

    //safely delete stock and customerDrinks
    for(int i = 0; i < numOfDrinks; ++i){
        delete stock[i];
        stock[i] = nullptr;
    }

    for(int i = 0; i < numOfCustomerDrinks; ++i){
        delete customerDrinks[i];
        customerDrinks[i] = nullptr; 
    }

    delete[] stock;
    delete customerDrinks;
    
    return 0;
}