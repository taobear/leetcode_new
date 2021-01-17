#include "minCostII.h"

#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int minCostII(int** costs, int costsSize, int* costsColSize)
{
    if (costsSize <= 0 || costsColSize[0] <= 0) {
        return 0;
    }

    int k = costsColSize[0];
    int dp[2][k];

    memset(dp, 0, sizeof(int) * 2 * k);

    int min1stId = 0;
    int min2rdId = 0;

    for (int i = 0; i < costsSize; i++) {
        int min1stTmp = -1;
        int min2rdTmp = -1;

        for (int j = 0; j < k; j++) {
            if (min1stId == j) {
                dp[(i + 1) % 2][j] = dp[i % 2][min2rdId] + costs[i][j];
            } else {
                dp[(i + 1) % 2][j] = dp[i % 2][min1stId] + costs[i][j];
            }

            if (min1stTmp == -1 || dp[(i + 1) % 2][j] < dp[(i + 1) % 2][min1stTmp]) {
                min2rdTmp = min1stTmp;
                min1stTmp = j;
            } else if (min2rdTmp == -1 || dp[(i + 1) % 2][j] < dp[(i + 1) % 2][min2rdTmp]) {
                min2rdTmp = j;
            }
        }

        min1stId = min1stTmp;
        min2rdId = min2rdTmp;
    }

    int result = INT_MAX;
    for (int j = 0; j < k; j++) {
        result = min(dp[costsSize % 2][j], result);
    }

    return result;
}