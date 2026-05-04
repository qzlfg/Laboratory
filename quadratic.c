#include <math.h>
#include <stdio.h>

#include "quadratic.h"

Roots solve_quadratic(double a, double b, double c)
{
    Roots res;
    double eps = 1e-7;

    if (fabs(a) < eps)
    {
        printf("Невозможно вычисление значений корней\n");
        res.count = 0;
        res.x1 = res.x2 = 0;
        return res;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < -eps)
    {
        printf("Корней нет\n");
        res.count = 0;
        res.x1 = res.x2 = 0;
        return res;
    }

    else if (fabs(discriminant) < eps)
    {
        double x = -b / (2 * a);
        res.count = 1;
        res.x1 = x;
        res.x2 = 0;
        return res;
    }

    else
    {
        double q = -(b + (b > 0 ? 1 : -1) * sqrt(discriminant)) / 2.0;
        double x1 = q / a;
        double x2 = c / q;
        res.count = 2;
        res.x1 = (x1 < x2) ? x1 : x2;
        res.x2 = (x1 > x2) ? x1 : x2;
        return res;
    }
}
