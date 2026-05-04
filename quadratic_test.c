#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "quadratic.h"

int is_equal(Roots res, Roots check, double eps)
{
    if (res.count != check.count)
        return 0;
    if (!(res.x1 - check.x1 < eps))
        return 0;
    if (!(res.x2 - check.x2 < eps))
        return 0;
    return 1;
}

void test1()
{
    Roots res = solve_quadratic(0, 1, 1);
    Roots check = {0, 0, 0};
    assert(is_equal(res, check, 1e-4));
}

void test2()
{
    Roots res = solve_quadratic(1, 0, -1);
    Roots check = {-1, 1, 2};
    assert(is_equal(res, check, 1e-4));
}

void test3()
{
    Roots res = solve_quadratic(1, 0, 0);
    Roots check = {0, 0, 1};
    assert(is_equal(res, check, 1e-4));
}

void test4()
{
    Roots res = solve_quadratic(1, 0, 1);
    Roots check = {0, 0, 0};
    assert(is_equal(res, check, 1e-4));
}

void test5()
{
    Roots res = solve_quadratic(1, 0, -1e-7);
    Roots check = {-3e-4, 3e-4, 2};
    assert(is_equal(res, check, 1e-4));
}

void test6()
{
    Roots res = solve_quadratic(1, -1e+10, -1);
    Roots check = {-1e-10, 1e+10, 2};
    assert(is_equal(res, check, 1e-11));
}

void test7()
{
    Roots res = solve_quadratic(1, 0, -1e-8);
    Roots check = {0, 0, 1};
    assert(is_equal(res, check, 1e-7));
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}
