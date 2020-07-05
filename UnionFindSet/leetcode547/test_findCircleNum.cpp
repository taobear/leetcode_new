#include "findCircleNum.h"

#include <stdio.h>

void test1()
{
    int M1[] = {1, 1, 0};
    int M2[] = {1, 1, 0};
    int M3[] = {0, 0, 1};

    int *M[] = {M1, M2, M3};
    int MSize = sizeof(M) / sizeof(*M);
    int MColSize[] = {3, 3, 3};

    printf("test1(): %d\n", findCircleNum(M, MSize, MColSize));
}

void test2()
{
    int M1[] = {1, 1, 0};
    int M2[] = {1, 1, 1};
    int M3[] = {0, 1, 1};

    int *M[] = {M1, M2, M3};
    int MSize = sizeof(M) / sizeof(*M);
    int MColSize[] = {3, 3, 3};

    printf("test2(): %d\n", findCircleNum(M, MSize, MColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}