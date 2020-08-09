#include "getMaximumGold.h"

#include <stdlib.h>
#include <string.h>

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_BOTTOM
} Direction;

const int g_directions[DIR_BOTTOM][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define MAX_GRID_SIZE 15
int g_isGridVisited[MAX_GRID_SIZE * MAX_GRID_SIZE];

bool isGridInvalid(int **grid, int gridSize, int *gridColSize, int gridX, int gridY)
{
    if (gridX < 0 || gridX >= gridSize) {
        return true;
    }

    if (gridY < 0 || gridY >= gridColSize[gridX]) {
        return true;
    }

    if (grid[gridX][gridY] == 0) {
        return true;
    }

    return false;
}

int backTrack(int **grid, int gridSize, int *gridColSize, int gridX, int gridY)
{
    int maxGold = 0;
    for (int dir = DIR_UP; dir < DIR_BOTTOM; dir++) {
        int newGridX = g_directions[dir][0] + gridX;
        int newGridY = g_directions[dir][1] + gridY;
        if (isGridInvalid(grid, gridSize, gridColSize, newGridX, newGridY) == true) {
            continue;
        }

        int newGridMapId = newGridX * MAX_GRID_SIZE + newGridY;
        if (g_isGridVisited[newGridMapId] == 1) {
            continue;
        }

        int oldGridMapId = gridX * MAX_GRID_SIZE + gridY;
        g_isGridVisited[oldGridMapId] = 1;
        int gold = backTrack(grid, gridSize, gridColSize, newGridX, newGridY);
        maxGold = gold > maxGold ? gold : maxGold;
        g_isGridVisited[oldGridMapId] = 0;
    }

    return maxGold + grid[gridX][gridY];
}

bool isStartingPoint(int **grid, int gridSize, int *gridColSize, int gridX, int gridY)
{
    const int turnPointInValidFlag[DIR_BOTTOM][DIR_BOTTOM] = {
        {1, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 0, 1}
    };

    if (grid[gridX][gridY] == 0) {
        return false;
    }

    int inValidFlag[DIR_BOTTOM] = {0};
    int inValidCnt = 0;
    for (int dir = DIR_UP; dir < DIR_BOTTOM; dir++) {
        int newGridX = g_directions[dir][0] + gridX;
        int newGridY = g_directions[dir][1] + gridY;
        if (isGridInvalid(grid, gridSize, gridColSize, newGridX, newGridY)) {
            inValidFlag[dir] = 1;
            inValidCnt++;
        }
    }

    if (inValidCnt == 3 || inValidCnt == 4) {
        return true;
    }

    for (int i = DIR_UP; i < DIR_BOTTOM; i++) {
        int matchLen = 0;
        for (int j = DIR_UP; j < DIR_BOTTOM; j++) {
            if (inValidFlag[j] != turnPointInValidFlag[i][j]) {
                break;
            }

            matchLen++;
        }

        if (matchLen == 4) {
            return true;
        }
    }

    return false;
}

int getMaximumGold(int **grid, int gridSize, int *gridColSize)
{
    int result = 0;
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridColSize[row]; col++) {
            if (isStartingPoint(grid, gridSize, gridColSize, row, col) != true) {
                continue;
            }

            memset(g_isGridVisited, 0, MAX_GRID_SIZE * MAX_GRID_SIZE * sizeof(int));
            int tmpRslt = backTrack(grid, gridSize, gridColSize, row, col);
            result = tmpRslt > result ? tmpRslt : result;   
        }
    }

    return result;
}