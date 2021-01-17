#include "largestSumOfAverages.h"

#include <stdio.h>

void test1()
{
    int A[] = {9, 1, 2, 3, 9};
    int ASize = sizeof(A) / sizeof(*A);

    int K = 3;

    printf("test1(): %f\n", largestSumOfAverages(A, ASize, K));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}