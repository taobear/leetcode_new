#include "findCircleNum.h"

#define GRID_MAX_SIZE 500
int g_gridIdMap[GRID_MAX_SIZE];
int g_gridSize = 0;
int g_components = 0;

bool initGrid(int n)
{
    if (n > GRID_MAX_SIZE)
    {
        return false;
    }

    g_gridSize = n;
    g_components = n;
    for (int i = 0; i < n; ++i)
    {
        g_gridIdMap[i] = i;
    }
    return true;
}

int findRoot(int p)
{
    while (g_gridIdMap[p] != p)
    {
        p = g_gridIdMap[p];
    }

    return p;
}

void unionGrid(int p, int q)
{
    int pRoot = findRoot(p);
    int qRoot = findRoot(q);
    if (pRoot == qRoot)
    {
        return;
    }

    g_gridIdMap[pRoot] = q;
    g_components--;
}

int findCircleNum(int **M, int MSize, int *MColSize)
{
    if (initGrid(MSize) != true) {
        return 0;
    }

    for (int i = 0; i < MSize; ++i) {
        if (MColSize[i] != MSize) {
            return 0;
        }

        for (int j = 0; j < i; ++j) {
            if (M[i][j] != 1) {
                continue;
            }
            unionGrid(i, j);
        }
    }

    return g_components;
}