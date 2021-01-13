#include "assignBikes.h"

#include <stdlib.h>
#include <string.h>

#define MAX_BIKE_STATE 1024

int g_workerBikeDistance[MAX_BIKE_STATE];

int workerBikeDistance(int *worker, int *bike)
{
    return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
}

int helper(int** workers, int workerIndex, int workersSize, int** bikes, int bikeState, int bikesSize)
{
    if (workerIndex == workersSize) {
        return 0;
    }

    int minDist = INT_MAX;
    for (int bikeIndex = 0; bikeIndex < bikesSize; bikeIndex++) {
        if ((bikeState & (1 << bikeIndex)) != 0) {
            continue;
        }

        int dist = workerBikeDistance(workers[workerIndex], bikes[bikeIndex]);
        if (g_workerBikeDistance[bikeState | (1 << bikeIndex)] == -1) {
            dist += helper(workers, workerIndex + 1, workersSize, bikes, bikeState | (1 << bikeIndex), bikesSize);
        } else {
            dist += g_workerBikeDistance[bikeState | (1 << bikeIndex)];
        }

        minDist = minDist > dist ? dist : minDist;
    }

    g_workerBikeDistance[bikeState] = minDist;

    return minDist;
}

int assignBikes(int** workers, int workersSize, int* workersColSize, int** bikes, int bikesSize, int* bikesColSize)
{
    memset(g_workerBikeDistance, -1, sizeof(g_workerBikeDistance));

    return helper(workers, 0, workersSize, bikes, 0, bikesSize);
}