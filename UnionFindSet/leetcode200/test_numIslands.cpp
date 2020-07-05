#include "numIslands.h"

#include <stdio.h>

void test1()
{
    char grid1[] = "11110";
    char grid2[] = "11010";
    char grid3[] = "11000";
    char grid4[] = "00000";

    char *grid[] = {grid1, grid2, grid3, grid4};
    int gridSize = 4;
    int gridColSize[] = {5, 5, 5, 5};

    printf("test1(): %d\n", numIslands(grid, gridSize, gridColSize));
}

void test2()
{
    char grid1[] = "11000";
    char grid2[] = "11000";
    char grid3[] = "00100";
    char grid4[] = "00011";

    char *grid[] = {grid1, grid2, grid3, grid4};
    int gridSize = 4;
    int gridColSize[] = {5, 5, 5, 5};

    printf("test2(): %d\n", numIslands(grid, gridSize, gridColSize));
}

void test3()
{
    char grid1[] = "10111";
    char grid2[] = "10101";
    char grid3[] = "11101";

    char *grid[] = {grid1, grid2, grid3};
    int gridSize = 3;
    int gridColSize[] = {5, 5, 5};

    printf("test3(): %d\n", numIslands(grid, gridSize, gridColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}