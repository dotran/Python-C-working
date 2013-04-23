// This is my computational code written in C
#include <iostream>
#include "myheaders.h"

extern "C" {
    
    myClassCpp* myClassObj() {
        return new myClassCpp();
    }
    
    void myGreeting(myClassCpp* myGreetingObjC, int n) {
        myGreetingObjC->greetingCpp(n); // this is C (using "->"), not C++ (".")
    }
    
    
    void myHello(int n) {
        myHelloCpp(n);
    }
    
    double myDprod(double *x, int n) {
        return myDprodCpp(x, n);
    }
    
    void myDcumsum(double *y, double *x, int n) {
        myDcumsumCpp(y, x, n);
    }
    
}

