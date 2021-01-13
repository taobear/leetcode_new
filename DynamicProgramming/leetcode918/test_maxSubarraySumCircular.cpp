#include "maxSubarraySumCircular.h"

#include <stdio.h>

void test1()
{
    int A[] = {1, -2, 3, -2};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test1(): %d\n", maxSubarraySumCircular(A, ASize));
}

void test2()
{
    int A[] = {5, -3, 5};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test2(): %d\n", maxSubarraySumCircular(A, ASize));
}

void test3()
{
    int A[] = {3, -1, 2, -1};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test3(): %d\n", maxSubarraySumCircular(A, ASize));
}

void test4()
{
    int A[] = {3, -2, 2, -3};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test4(): %d\n", maxSubarraySumCircular(A, ASize));
}

void test5()
{
    int A[] = {-2, -3, -1};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test5(): %d\n", maxSubarraySumCircular(A, ASize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    test5();

    return 0;
}