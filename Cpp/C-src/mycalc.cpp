// This is my calculation code written in Cpp
#include <cstdio>

using namespace std;

double myDprodCpp(double *x, int n) {
    double y = 1.0;
    for (int i = 0; i < n; i++)
        y *= x[i];
    return y;
}

void myDcumsumCpp(double *y, double *x, int n) {
    y[0] = x[0];
    for (int i = 1; i < n; i++)
        y[i] = x[i] + y[i-1];
}

