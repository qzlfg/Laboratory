#include <stdio.h>
#include "integral.h"

double square(double x){
    return x*x;
}

double method_trapezoid(double a, double b, int n, double (*func)(double)){
    if (n<=0){
        printf("n должно быть больше нуля");
        return 0.0;
    }
    double total_square = 0;
    double h = (b-a)/n;
    total_square += (func(a) + func(b))/2.0;
    for (int i = 1; i<n; i++){
        double x = a + i*h;
        total_square+= func(x);
    }
    total_square *= h;
    return total_square;   
}
