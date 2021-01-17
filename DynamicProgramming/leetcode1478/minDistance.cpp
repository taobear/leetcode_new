#include "minDistance.h"

#include <stdlib.h>
#include <stdio.h>
int min(int a, int b)
{
    return a < b ? a : b;
}

int intComare(const void* a, const void* b)
{
    return *(const int*)a - *(const int*)b;
}

int minDistance(int* houses, int housesSize, int k)
{
    if (housesSize <= k) {
        return 0;
    }

    qsort(houses, housesSize, sizeof(int), intComare);

    int minDist[housesSize][housesSize];

    minDist[housesSize - 1][housesSize - 1] = 0;
    for (int i = housesSize - 2; i >= 0; i--) {
        minDist[i][i] = 0;
        minDist[i][i + 1] = houses[i + 1] - houses[i];
        for (int j = i + 2; j < housesSize; j++) {
            minDist[i][j] = minDist[i + 1][j - 1] + houses[j] - houses[i];
        }
    }

    int dp[housesSize][k];
    for (int i = 0; i < housesSize; i++) {
        dp[i][0] = minDist[0][i];
        for (int j = 1; j < k && j <= i; j++) {
            dp[i][j] = INT_MAX;
            for (int t = 0; t < i; t++) {
                dp[i][j] = min((t > j - 1 ? dp[t][j - 1] : 0) + minDist[t + 1][i], dp[i][j]);
            }
        }
    }

    return dp[housesSize - 1][k - 1];
}