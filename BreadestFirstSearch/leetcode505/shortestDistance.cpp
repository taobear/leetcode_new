#include "shortestDistance.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_ROW_SIZE 100
#define GRID_COL_SIZE 100

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_BOTTOM
} DIR;

typedef struct {
    int x;
    int y;
    DIR dir;
} Grid;

int Queue_Size();
void Queue_Init();
void Queue_Push(Grid grid);
Grid Queue_PopFront();

int distance[GRID_ROW_SIZE][GRID_COL_SIZE][DIR_BOTTOM];
int move[DIR_BOTTOM][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValidGrid(int **maze, int mazeSize, int *mazeColSize, int gridX, int gridY)
{
    if (gridX < 0 || gridX >= mazeSize) {
        return false;
    }

    if (gridY < 0 || gridY >= mazeColSize[gridX]) {
        return false;
    }

    if (maze[gridX][gridY] == 1) {
        return false;
    }

    return true;
}

int shortestDistance(int **maze, int mazeSize, int *mazeColSize, int *start, int startSize, int *destination, int destinationSize)
{
    if (maze == NULL || mazeSize == 0 || mazeColSize == NULL) {
        return -1;
    }

    if (start == NULL || startSize != 2) {
        return -1;
    }

    if (destination == NULL || destinationSize != 2) {
        return -1;
    }

    for (int i = 0; i < mazeSize; ++i) {
        for (int j = 0; j < mazeColSize[i]; ++j) {
            for (int k = 0; k < 4; ++k) {
                distance[i][j][k] = -1;
            }
        }
    }

    int startX = start[0], startY = start[1];
    int destX = destination[0], destY = destination[1];
    Queue_Init();
    for (int i = 0; i < 4; ++i) {
        Queue_Push(Grid{startX, startY, DIR(i)});
        distance[startX][startY][i] = 0;
    }

    while (Queue_Size()) {
        Grid front = Queue_PopFront();
        int newX = front.x + move[front.dir][0];
        int newY = front.y + move[front.dir][1];
        if (isValidGrid(maze, mazeSize, mazeColSize, newX, newY)) {
            if (distance[newX][newY][front.dir] != -1) {
                continue;
            }
                
            Queue_Push(Grid{newX, newY, front.dir});
            distance[newX][newY][front.dir] = distance[front.x][front.y][front.dir] + 1;
        } else {
            if (front.x == destX && front.y == destY) {
                return distance[destX][destY][front.dir];
            }

            for (int i = 0; i < 4; ++i) {
                newX = front.x + move[i][0];
                newY = front.y + move[i][1];
                if (isValidGrid(maze, mazeSize, mazeColSize, newX, newY)) {
                    if (distance[newX][newY][i] != -1) {
                        continue;
                    }

                    Queue_Push(Grid{newX, newY, DIR(i)});
                    distance[newX][newY][i] = distance[front.x][front.y][front.dir] + 1;
                }
            }
        }
    }

    return -1;
}

#define MAX_QUEUE_SIZE (GRID_ROW_SIZE * GRID_COL_SIZE)
typedef struct {
    Grid arr[MAX_QUEUE_SIZE];
    int begin;
    int end;
} Queue;
Queue g_myQueue;

int Queue_Size()
{
    return (g_myQueue.end + MAX_QUEUE_SIZE - g_myQueue.begin) % MAX_QUEUE_SIZE;
}

void Queue_Init()
{
    g_myQueue.begin = 0;
    g_myQueue.end = 0;
}

void Queue_Push(Grid grid)
{
    int tail = g_myQueue.end;
    g_myQueue.arr[tail] = grid;
    g_myQueue.end = (tail + 1) % MAX_QUEUE_SIZE;
}

Grid Queue_PopFront()
{
    int front = g_myQueue.begin;
    Grid grid = g_myQueue.arr[front];
    g_myQueue.begin = (front + 1) % MAX_QUEUE_SIZE;
    return grid;
}