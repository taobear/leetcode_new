#include "combinationSum2.h"

#include <stdio.h>
#include <stdlib.h>

void print_2d_nums(int **subset, int subsetNum, int *subsetSize)
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

void free_2d_nums(int **subset, int subsetNum, int *subsetSize)
{
    for (int index = 0; index < subsetNum; ++index) {
        free(subset[index]);
    }

    free(subset);
    free(subsetSize);
}

void test1()
{
    int candidates[] = {10, 1, 2, 7, 6, 1, 5};
    int candidatesSize = sizeof(candidates) / sizeof(*candidates);
    int target = 8;

    int subsetNum;
    int *subsetSize;
    int **subset;
    subset = combinationSum2(candidates, candidatesSize, target, &subsetNum, &subsetSize);

    printf("test1(): \n");
    print_2d_nums(subset, subsetNum, subsetSize);
    free_2d_nums(subset, subsetNum, subsetSize);
}

void test2()
{
    int candidates[] = {2, 5, 2, 1, 2};
    int candidatesSize = sizeof(candidates) / sizeof(*candidates);
    int target = 5;

    int subsetNum;
    int *subsetSize;
    int **subset;
    subset = combinationSum2(candidates, candidatesSize, target, &subsetNum, &subsetSize);

    printf("test2(): \n");
    print_2d_nums(subset, subsetNum, subsetSize);
    free_2d_nums(subset, subsetNum, subsetSize);
}

void test3()
{
    int candidates[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int candidatesSize = sizeof(candidates) / sizeof(*candidates);
    int target = 5;

    int subsetNum;
    int *subsetSize;
    int **subset;
    subset = combinationSum2(candidates, candidatesSize, target, &subsetNum, &subsetSize);

    printf("test3(): \n");
    print_2d_nums(subset, subsetNum, subsetSize);
    free_2d_nums(subset, subsetNum, subsetSize);
}

void test4()
{
    int candidates[] = {3, 1, 3, 5, 1, 1};
    int candidatesSize = sizeof(candidates) / sizeof(candidatesSize);
    int target = 8;

    int subsetNum;
    int *subsetSize;
    int **subset;
    subset = combinationSum2(candidates, candidatesSize, target, &subsetNum, &subsetSize);

    printf("test3(): \n");
    print_2d_nums(subset, subsetNum, subsetSize);
    free_2d_nums(subset, subsetNum, subsetSize);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}