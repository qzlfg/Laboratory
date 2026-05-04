#ifndef HEADER_H
#define HEADER_H

typedef struct
{
    double x1;
    double x2;
    int count;
} Roots;

Roots solve_quadratic(double a, double b, double c);

#endif