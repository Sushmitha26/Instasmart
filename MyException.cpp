#include <iostream>
#include <exception>
using namespace std;
class MyException: public exception{
    public:
    virtual const char* what() const throw(){
        //fill your code here
        return "Order cancelling";
    }
};






