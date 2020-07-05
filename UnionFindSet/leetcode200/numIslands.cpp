#include "numIslands.h"

#include <stdlib.h>

#define GRID_MAX_SIZE 100000
int g_gridIdMap[GRID_MAX_SIZE];
int g_landCount = 0;

int g_directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int findRoot(int id)
{
    while (g_gridIdMap[id] != id) {
        id = g_gridIdMap[id];
    }
    return id;
}

void unionRoot(int p, int q)
{
    int rootP = findRoot(p);
    int rootQ = findRoot(q);
    if (rootP == rootQ) {
        return;
    }

    g_gridIdMap[rootP] = q;
    g_landCount--;
}

int numIslands(char **grid, int gridSize, int *gridColSize)
{
    if (grid == NULL || gridSize == 0 || gridColSize == 0) {
        return 0;
    }

    int rowSize = gridSize;
    int colSize = *gridColSize;
    g_landCount = 0;
    for (int row = 0; row < rowSize; ++row) {
        for (int col = 0; col < colSize; ++col) {
            if (grid[row][col] != '1') {
                continue;
            }

            int curIndex = row * colSize + col;
            g_gridIdMap[curIndex] = curIndex;
            g_landCount++;
        }
    }

    for (int row = 0; row < rowSize; ++row) {
        for (int col = 0; col < colSize; ++col) {
            if (grid[row][col] != '1') {
                continue;
            }

            int preRow, preCol, preDir;
            int curIndex = row * colSize + col;
            for (preDir = 0; preDir < 4; ++preDir) {
                preRow = g_directions[preDir][0] + row;
                if (preRow < 0 || preRow >= rowSize) {
                    continue;
                }

                preCol = g_directions[preDir][1] + col;
                if (preCol < 0 || preCol >= colSize) {
                    continue;
                }

                if (grid[preRow][preCol] != '1') {
                    continue;
                }
                
                int preIndex = preRow * colSize + preCol;
                unionRoot(preIndex, curIndex);
            }
        }
    }

    return g_landCount;
}