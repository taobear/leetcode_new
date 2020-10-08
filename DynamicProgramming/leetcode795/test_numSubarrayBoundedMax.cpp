#include "numSubarrayBoundedMax.h"

#include <stdio.h>

void test1()
{
    int A[] = {2, 1, 4, 3};
    int ASize = sizeof(A) / sizeof(*A);
    int L = 2, R = 3;

    printf("test1(): %d\n", numSubarrayBoundedMax(A, ASize, L, R));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}