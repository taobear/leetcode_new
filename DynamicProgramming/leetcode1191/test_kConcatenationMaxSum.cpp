#include "kConcatenationMaxSum.h"

#include <stdio.h>

void test1()
{
    int arr[] = {1, 2};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int k = 3;

    printf("test1(): %d\n", kConcatenationMaxSum(arr, arrSize, k));
}

void test2()
{
    int arr[] = {1, -2, 1};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int k = 5;
    
    printf("test2(): %d\n", kConcatenationMaxSum(arr, arrSize, k));
}

void test3()
{
    int arr[] = {-1, -2};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int k = 7;

    printf("test3(): %d\n", kConcatenationMaxSum(arr, arrSize, k));
}

void test4()
{
    int arr[] = { -5, -2, 0, 0, 3, 9, -2, -5, 4 };
    int arrSize = sizeof(arr) / sizeof(*arr);
    int k = 5;

    printf("test4(): %d\n", kConcatenationMaxSum(arr, arrSize, k));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}