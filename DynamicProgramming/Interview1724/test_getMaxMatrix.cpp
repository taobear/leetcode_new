#include "getMaxMatrix.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_1d_nums(int* nums, int numsSize)
{
    printf("[");
    for (int i = 0; i < numsSize - 1; ++i) {
        printf("%d, ", nums[i]);
    }

    printf("%d]\n", nums[numsSize - 1]);
}

void test1()
{
    int matrix1[] = {-1, 0};
    int matrix2[] = {0, -1};

    int *matrix[] = {matrix1, matrix2};
    int matrixSize = sizeof(matrix) / sizeof(*matrix);
    int matrixColSize[] = {2, 2};

    int *ret, returnSize;

    ret = getMaxMatrix(matrix, matrixSize, matrixColSize, &returnSize);

    print_1d_nums(ret, returnSize);

    free(ret);
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}