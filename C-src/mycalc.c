// This is my calculation code written in C
#include <stdio.h>
#include "myheaders.h"

#ifdef __cplusplus
extern "C" {
#endif

double myDprod(double *x, int n) {
    double y = 1.0;
    for (int i = 0; i < n; i++)
        y *= x[i];
    return y;
}

void myDcumsum(double *y, double *x, int n) {
    y[0] = x[0];
    for (int i = 1; i < n; i++)
        y[i] = x[i] + y[i-1];
}

#ifdef __cplusplus
}
#endif