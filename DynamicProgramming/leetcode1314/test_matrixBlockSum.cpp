#include "matrixBlockSum.h"

#include <stdio.h>
#include <stdlib.h>

void print_2d_nums(int** subset, int subsetNum, int* subsetSize)
{
    printf("[\n");

    for (int index = 0; index < subsetNum; ++index) {
        printf("  [");

        for (int j = 0; j < subsetSize[index] - 1; ++j) {
            printf("%d, ", subset[index][j]);
        }
        if (subsetSize[index] - 1 >= 0) {
            printf("%d", subset[index][subsetSize[index] - 1]);
        }

        printf("]\n");
    }

    printf("]\n");
}

void free_2d_nums(int** subset, int subsetNum, int* subsetSize)
{
    for (int index = 0; index < subsetNum; ++index) {
        free(subset[index]);
    }

    free(subset);
    free(subsetSize);
}

void test1()
{
    int mat1[] = {1, 2, 3};
    int mat2[] = {4, 5, 6};
    int mat3[] = {7, 8, 9};

    int *mat[] = {mat1, mat2, mat3};
    int matSize = sizeof(mat) / sizeof(*mat);
    int matColSize[] = {3, 3, 3};
    int K = 1;
    
    int retMatSize = 0;
    int *retMatColSize;
    int **retMat = matrixBlockSum(mat, matSize, matColSize, K, &retMatSize, &retMatColSize);

    printf("test1(): \n");

    print_2d_nums(retMat, retMatSize, retMatColSize);
    free_2d_nums(retMat, retMatSize, retMatColSize);
}

void test2()
{
    int mat1[] = { 1, 2, 3 };
    int mat2[] = { 4, 5, 6 };
    int mat3[] = { 7, 8, 9 };

    int* mat[] = { mat1, mat2, mat3 };
    int matSize = sizeof(mat) / sizeof(*mat);
    int matColSize[] = { 3, 3, 3 };
    int K = 2;

    int retMatSize = 0;
    int* retMatColSize;
    int** retMat = matrixBlockSum(mat, matSize, matColSize, K, &retMatSize, &retMatColSize);

    printf("test2(): \n");

    print_2d_nums(retMat, retMatSize, retMatColSize);
    free_2d_nums(retMat, retMatSize, retMatColSize);
}

void test3()
{
    int mat1[] = {67, 64, 78};
    int mat2[] = {99, 98, 38};
    int mat3[] = {82, 46, 46};
    int mat4[] = { 6, 52, 55};
    int mat5[] = {55, 99, 45};

    int *mat[] = {mat1, mat2, mat3, mat4, mat5};
    int matSize = sizeof(mat) / sizeof(*mat);
    int matColSize[] = { 3, 3, 3, 3, 3 };
    int K = 3;

    int retMatSize = 0;
    int* retMatColSize;
    int** retMat = matrixBlockSum(mat, matSize, matColSize, K, &retMatSize, &retMatColSize);

    printf("test3(): \n");

    print_2d_nums(retMat, retMatSize, retMatColSize);
    free_2d_nums(retMat, retMatSize, retMatColSize);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}
