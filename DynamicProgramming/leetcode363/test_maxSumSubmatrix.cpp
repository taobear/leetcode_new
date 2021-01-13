#include "maxSumSubmatrix.h"

#include <stdio.h>

void test1()
{
    int matrix1[] = {1,  0, 1};
    int matrix2[] = {0, -2, 3};

    int *matrix[] = {matrix1, matrix2};

    int matrixSize = sizeof(matrix) / sizeof(*matrix);
    int matrixColSize[] = {3, 3};

    int k = 2;

    printf("test1(): %d\n", maxSumSubmatrix(matrix, matrixSize, matrixColSize, k));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}