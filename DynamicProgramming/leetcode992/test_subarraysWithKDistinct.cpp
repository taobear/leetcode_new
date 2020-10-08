#include "subarraysWithKDistinct.h"

#include <stdio.h>

void test1()
{
    int A[] = {1, 2, 1, 2, 3};
    int ASize = sizeof(A) / sizeof(*A);
    int K = 2;

    printf("test1(): %d\n", subarraysWithKDistinct(A, ASize, K));
}

void test2()
{
    int A[] = {1, 2, 1, 3, 4};
    int ASize = sizeof(A) / sizeof(*A);
    int K = 3;

    printf("test2(): %d\n", subarraysWithKDistinct(A, ASize, K));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}