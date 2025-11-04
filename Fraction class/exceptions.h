#include <exception>
#include <string> 

using namespace std;

class  invalidDenominator : public exception{

    string message;

    public:
    invalidDenominator(string msg) : message(msg) {}

    const char* what() {
        return message.c_str();
    }
};

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }
