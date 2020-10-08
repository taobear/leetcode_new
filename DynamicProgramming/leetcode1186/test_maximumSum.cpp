#include "maximumSum.h"

#include <stdio.h>

void test1()
{
    int arr[] = {1, -2, 0, 3};
    int arrSize = sizeof(arr) / sizeof(*arr);

    printf("test1(): %d\n", maximumSum(arr, arrSize));
}

void test2()
{
    int arr[] = {1, -2, -2, 3};
    int arrSize = sizeof(arr) / sizeof(*arr);

    printf("test2(): %d\n", maximumSum(arr, arrSize));
}

void test3()
{
    int arr[] = {-1, -1, -1, -1};
    int arrSize = sizeof(arr) / sizeof(*arr);

    printf("test3(): %d\n", maximumSum(arr, arrSize));
}

void test4()
{
    int arr[] = {2, 1, -2, -5, -2};
    int arrSize = sizeof(arr) / sizeof(*arr);

    printf("test4(): %d\n", maximumSum(arr, arrSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}