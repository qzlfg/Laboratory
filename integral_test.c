#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "integral.h"
#define EPSILON 1e-3

int main(){
    printf("Запуск тестов для integral.c\n");
    double a = 0;
    double b = 4;
    int n = 10000;
    assert((fabs(method_trapezoid(a, b, n, sqrt) - 5.33333) < EPSILON));

    a= 1;
    b = 4;
    assert((fabs(method_trapezoid(a, b, n, square) - 21) < EPSILON));

    a = 0;
    b = 2;
    n = 1000;
    assert((fabs(method_trapezoid(a, b, n, sin) - 1.41618) < EPSILON));
    
    
}
