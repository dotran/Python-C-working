// This is a Cpp code wrapped as C
#include <iostream>
// #include "myheaders.h

class myClass{
    public:
        void greeting(){
            std::cout << "Linh says Hello World!" << std::endl;
        }
};

extern "C" {
    myClass* myNewClass() {
        return new myClass();
    }

    void myNewGreeting(myClass* myGreetingClass) {
        myGreetingClass->greeting();
    }
}
