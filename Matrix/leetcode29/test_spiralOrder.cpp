#include "spiralOrder.h"

#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int arraySize)
{
    if (array == NULL || arraySize == 0) {
        return;
    }

    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
}

void test1()
{
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};
    int *matrix[] = {row1, row2, row3};
    int matrixSize = 3;
    int matrixColSize[] = {3, 3, 3};

    int *ret, returnSize;
    ret = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);

    printf("test1(): ");
    print_array(ret, returnSize);
    printf("\n");

    free(ret);
}

void test2()
{
    int row1[] = {1, 2, 3, 4};
    int row2[] = {5, 6, 7, 8};
    int row3[] = {9, 10, 11, 12};
    int *matrix[] = {row1, row2, row3};
    int matrixSize = sizeof(matrix) / sizeof(*matrix);
    int matrixColSize[] = {4, 4, 4};

    int *ret, returnSize;
    ret = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);

    printf("test2(): ");
    print_array(ret, returnSize);
    printf("\n");

    free(ret);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}