#include "minPushBox.h"

#include <stdio.h>

void test1()
{
    char grid1[] = {'#', '#', '#', '#', '#', '#'};
    char grid2[] = {'#', 'T', '#', '#', '#', '#'};
    char grid3[] = {'#', '.', '.', 'B', '.', '#'};
    char grid4[] = {'#', '.', '#', '#', '.', '#'};
    char grid5[] = {'#', '.', '.', '.', 'S', '#'};
    char grid6[] = {'#', '#', '#', '#', '#', '#'};

    char *grid[] = {grid1, grid2, grid3, grid4, grid5, grid6};
    int gridSize = sizeof(grid) / sizeof(*grid);
    int gridColSize[] = {6, 6, 6, 6, 6, 6};

    printf("test1(): %d\n", minPushBox(grid, gridSize, gridColSize));
}

void test2()
{
    char grid1[] = { '#', '#', '#', '#', '#', '#' };
    char grid2[] = { '#', 'T', '#', '#', '#', '#' };
    char grid3[] = { '#', '.', '.', 'B', '.', '#' };
    char grid4[] = { '#', '#', '#', '#', '.', '#' };
    char grid5[] = { '#', '.', '.', '.', 'S', '#' };
    char grid6[] = { '#', '#', '#', '#', '#', '#' };

    char* grid[] = { grid1, grid2, grid3, grid4, grid5, grid6 };
    int gridSize = sizeof(grid) / sizeof(*grid);
    int gridColSize[] = { 6, 6, 6, 6, 6, 6 };

    printf("test2(): %d\n", minPushBox(grid, gridSize, gridColSize));
}

void test3()
{
    char grid1[] = { '#', '#', '#', '#', '#', '#' };
    char grid2[] = { '#', 'T', '.', '.', '#', '#' };
    char grid3[] = { '#', '.', '#', 'B', '.', '#' };
    char grid4[] = { '#', '.', '.', '.', '.', '#' };
    char grid5[] = { '#', '.', '.', '.', 'S', '#' };
    char grid6[] = { '#', '#', '#', '#', '#', '#' };

    char* grid[] = { grid1, grid2, grid3, grid4, grid5, grid6 };
    int gridSize = sizeof(grid) / sizeof(*grid);
    int gridColSize[] = { 6, 6, 6, 6, 6, 6 };

    printf("test3(): %d\n", minPushBox(grid, gridSize, gridColSize));
}

void test4()
{
    char grid1[] = { '#', '#', '#', '#', '#', '#', '#' };
    char grid2[] = { '#', 'S', '#', '.', 'B', 'T', '#' };
    char grid3[] = { '#', '#', '#', '#', '#', '#', '#' };

    char* grid[] = { grid1, grid2, grid3};
    int gridSize = sizeof(grid) / sizeof(*grid);
    int gridColSize[] = { 7, 7, 7 };

    printf("test4(): %d\n", minPushBox(grid, gridSize, gridColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}