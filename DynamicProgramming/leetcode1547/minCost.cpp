#include "minCost.h"

#include <stdlib.h>

int intCompare(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}

int intMin(int a, int b)
{
    return a < b ? a : b;
}

int minCost(int n, int *cuts, int cutsSize)
{
    qsort(cuts, cutsSize, sizeof(int), intCompare);

    int dp[cutsSize + 2][cutsSize + 2];
    for (int len = 1; len <= cutsSize + 1; len++) {
        for (int i = 0; i <= cutsSize; i++) {
            if (len == 1) {
                dp[i][i + len] = 0;
                continue;
            }

            int j = i + len; // 结束位置
            if (j > cutsSize + 1) {
                break;
            }

            int left = i == 0 ? 0 : cuts[i - 1];
            int right = j == cutsSize + 1 ? n : cuts[j - 1];

            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = intMin(dp[i][j], dp[i][k] + dp[k][j] + right - left);
            }    
        }
    }

    return dp[0][cutsSize + 1];
}