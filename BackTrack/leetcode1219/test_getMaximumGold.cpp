#include "getMaximumGold.h"

#include <stdio.h>

void test1()
{
    int grid1[] = {0, 6, 0};
    int grid2[] = {5, 8, 7};
    int grid3[] = {0, 9, 0};

    int *grid[] = { grid1, grid2, grid3 };
    int gridSize = sizeof(grid) / sizeof(*grid);

    int gridColSize[] = { 3, 3, 3};

    printf("test1(): %d\n", getMaximumGold(grid, gridSize, gridColSize));
}

void test2()
{
    int grid1[] = {1, 0, 7};
    int grid2[] = {2, 0, 6};
    int grid3[] = {3, 4, 5};
    int grid4[] = {0, 3, 0};
    int grid5[] = {9, 0, 20};

    int *grid[] = {grid1, grid2, grid3, grid4, grid5};
    int gridSize = sizeof(grid) / sizeof(*grid);

    int gridColSize[] = {3, 3, 3, 3, 3};

    printf("test2(): %d\n", getMaximumGold(grid, gridSize, gridColSize));
}

void test3()
{
    int grid1[] = {0, 0, 34, 0, 5, 0, 7, 0, 0, 0};
    int grid2[] = {0, 0, 0, 0, 21, 0, 0, 0, 0, 0};
    int grid3[] = {0, 18, 0, 0, 8, 0, 0, 0, 4, 0};
    int grid4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int grid5[] = {15, 0, 0, 0, 0, 22, 0, 0, 0, 21};
    int grid6[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int grid7[] = {0, 7, 0, 0, 0, 0, 0, 0, 38, 0};

    int *grid[] = {grid1, grid2, grid3, grid4, grid5, grid6, grid7};
    int gridSize = sizeof(grid) / sizeof(*grid);

    int gridColSize[] = { 10, 10, 10, 10, 10, 10, 10};

    printf("test3(): %d\n", getMaximumGold(grid, gridSize, gridColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}