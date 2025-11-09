#include <iostream>

using namespace std;

class Drink{
    const char* name = nullptr;
    int temperature = 0;

    public:
    Drink(const char* _name, int _temperature) : name (_name), temperature(_temperature){}

    virtual const char* getName(){
        return name;
    }
    virtual void describe(){cout<<"bro";}
    virtual ~Drink() = default;

};

class Wine : public Drink{
    int year;
    const char* color;

    public: 
    Wine(const char* _name, int _year, int _temperature, const char* _color)
        : Drink(_name, _temperature), year(_year), color(_color) {}

};
class CarmelEmeraldRazling : public Wine{
    public:
    CarmelEmeraldRazling(int _year, int _temperature)
        : Wine("Carmel Emerald Razling", _year, _temperature, "white") {}
};

class GolanSmadar : public Wine{
    public:
    GolanSmadar(int _year, int _temperature)
        : Wine("Golan Smadar", _year, _temperature, "white") {}
};

class YardenSherdona : public Wine{
    public:
    YardenSherdona(int _year, int _temperature)
        : Wine("Yarden Sherdona", _year, _temperature, "white") {}
};

class Keanti : public Wine{
    public:
    Keanti(int _year, int _temperature)
        : Wine("Kenati", _year, _temperature, "white") {}
};

class YardenHarChermonAdom : public Wine{
    public:
    YardenHarChermonAdom(int _year, int _temperature)
        : Wine("Yarden Har Chermon Adom", _year, _temperature, "white") {}
};

class YardenKavernaSovinion : public Wine{
    public:
    YardenKavernaSovinion(int _year, int _temperature)
        : Wine("Yarden Kaverna Sovinion", _year, _temperature, "white") {}
};

class ChateauMargot : public Wine{
    public:
    ChateauMargot(int _year, int _temperature)
        : Wine("Chateau Margot", _year, _temperature, "white") {}
};

class Beer : public Drink{
    public: 

    Beer(const char* _name, int _temperature)
        : Drink(_name, _temperature) {}

    void describe() override {cout<<"in";}
     
};

class Heineken : public Beer {
    public:
    Heineken(int _temperature) : Beer("Heineken", _temperature) {}
};

class Tuborg : public Beer {
    public:
    Tuborg(int _temperature) : Beer("Tuborg", _temperature) {}
};

class Goldstar : public Beer {
    public:
    Goldstar(int _temperature) : Beer("Goldstar", _temperature) {}
};

class Maccabi : public Beer {
    public:
    Maccabi(int _temperature) : Beer("Maccabi", _temperature) {}
};



