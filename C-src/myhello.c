// This is my simple code written in C
#include <stdio.h>
#include "myheaders.h"

#ifdef __cplusplus
extern "C" {
#endif

void myHello(int n) {
    for (int i = 0; i < n; i++)
        printf("C says hello to Do!\n");
}

#ifdef __cplusplus
}
#endif
