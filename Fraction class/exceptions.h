#include <exception>
#include <string> 

using namespace std;

class  invalidInput : public exception{

    string message;

    public:
    invalidInput(string msg) : message(msg) {}

    const char* what() {
        return message.c_str();
    }
};

