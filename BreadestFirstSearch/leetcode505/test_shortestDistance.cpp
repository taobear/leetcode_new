#include "shortestDistance.h"

#include <stdio.h>

void test1()
{
    int mazeRow0[] = {0, 0, 1, 0, 0};
    int mazeRow1[] = {0, 0, 0, 0, 0};
    int mazeRow2[] = {0, 0, 0, 1, 0};
    int mazeRow3[] = {1, 1, 0, 1, 1};
    int mazeRow4[] = {0, 0, 0, 0, 0};

    const int mazeSize = 5;
    int *maze[mazeSize] = {mazeRow0, mazeRow1, mazeRow2, mazeRow3, mazeRow4};
    int mazeColSize[mazeSize] = {5, 5, 5, 5, 5};

    int start[] = {0, 4}, startSize = 2;
    int destination[] = {4, 4}, destinationSize = 2;

    printf("test1() distance: %d\n", 
        shortestDistance(maze, mazeSize, mazeColSize, start, startSize, destination, destinationSize));
}

void test2()
{
    int mazeRow0[] = {0, 0, 1, 0, 0};
    int mazeRow1[] = {0, 0, 0, 0, 0};
    int mazeRow2[] = {0, 0, 0, 1, 0};
    int mazeRow3[] = {1, 1, 0, 1, 1};
    int mazeRow4[] = {0, 0, 0, 0, 0};

    const int mazeSize = 5;
    int *maze[mazeSize] = {mazeRow0, mazeRow1, mazeRow2, mazeRow3, mazeRow4};
    int mazeColSize[mazeSize] = {5, 5, 5, 5, 5};

    int start[] = {0, 4}, startSize = 2;
    int destination[] = {3, 2}, destinationSize = 2;

    printf("test2() distance: %d\n",
        shortestDistance(maze, mazeSize, mazeColSize, start, startSize, destination, destinationSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    getchar();

    return 0;
}