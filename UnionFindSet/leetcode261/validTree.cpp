#include "validTree.h"

#include <stdlib.h>

#define GRID_MAX_SIZE 100000
int g_gridIdMap[GRID_MAX_SIZE];
int g_landCount = 0;

int findRoot(int id)
{
    while (g_gridIdMap[id] != id) {
        id = g_gridIdMap[id];
    }
    return id;
}

bool unionRoot(int p, int q)
{
    int rootP = findRoot(p);
    int rootQ = findRoot(q);
    if (rootP == rootQ) {
        return false;
    }

    g_gridIdMap[rootP] = q;
    g_landCount--;
    return true;
}

bool validTree(int n, int **edges, int edgesSize, int *edgesColSize)
{
    if (n == 0 || edges == NULL) {
        return true;
    }

    g_landCount = 0;
    for (int i = 0; i < n; ++i) {
        g_gridIdMap[i] = i;
        g_landCount++;
    }

    for (int i = 0; i < edgesSize; ++i) {
        int srcId = edges[i][0];
        int tarId = edges[i][1];
        if (!unionRoot(srcId, tarId)) {
            return false;
        }
    }

    if (g_landCount != 1) {
        return false;
    }

    return true;
}