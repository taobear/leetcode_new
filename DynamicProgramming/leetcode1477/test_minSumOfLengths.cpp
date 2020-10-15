#include "minSumOfLengths.h"

#include <stdio.h>

void test1()
{
    int arr[] = {3, 2, 2, 4, 3};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int target = 3;

    printf("test1(): %d\n", minSumOfLengths(arr, arrSize, target));
}

void test2()
{
    int arr[] = {7, 3, 4, 7};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int target = 7;

    printf("test2(): %d\n", minSumOfLengths(arr, arrSize, target));
}

void test3()
{
    int arr[] = {4, 3, 2, 6, 2, 3, 4};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int target = 6;

    printf("test3(): %d\n", minSumOfLengths(arr, arrSize, target));
}

void test4()
{
    int arr[] = {5, 5, 4, 4, 5};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int target = 3;

    printf("test4(): %d\n", minSumOfLengths(arr, arrSize, target));
}

void test5()
{
    int arr[] = {3, 1, 1, 1, 5, 1, 2, 1};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int target = 3;

    printf("test5(): %d\n", minSumOfLengths(arr, arrSize, target));
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
