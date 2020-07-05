#include "countComponents.h"

#define GRID_MAX_SIZE 100000
int g_gridIdMap[GRID_MAX_SIZE];
int g_gridSize = 0;
int g_components = 0;

bool initGrid(int n)
{
    if (n > GRID_MAX_SIZE) {
        return false;
    }

    g_gridSize = n;
    g_components = n;
    for (int i = 0; i < n; ++i) {
        g_gridIdMap[i] = i;
    }
    return true;
}

int findRoot(int p)
{
    while (g_gridIdMap[p] != p) {
        p = g_gridIdMap[p];
    }

    return p;
}

void unionGrid(int p, int q)
{
    int pRoot = findRoot(p);
    int qRoot = findRoot(q);
    if (pRoot == qRoot) {
        return;
    }

    g_gridIdMap[pRoot] = q;
    g_components--;
}

int countComponents(int n, int **edges, int edgesSize, int *edgesColSize)
{
    if (initGrid(n) != true) {
        return 0;
    }

    for (int e = 0; e < edgesSize; ++e) {
        if (edgesColSize[e] != 2) {
            return 0;
        }

        int p = edges[e][0];
        int q = edges[e][1];
        unionGrid(p, q);
    }

    return g_components;
}