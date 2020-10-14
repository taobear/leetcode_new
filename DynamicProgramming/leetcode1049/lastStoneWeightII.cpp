#include "lastStoneWeightII.h"

int max(int a, int b)
{
    return a < b ? b : a;
}

int lastStoneWeightII(int* stones, int stonesSize)
{
    int sum = 0;
    for (int i = 0; i < stonesSize; i++) {
        sum += stones[i];
    }

    int dp[stonesSize + 1][sum / 2 + 1];
    for (int i = 0; i <= stonesSize; i++) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= sum / 2; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= stonesSize; i++) {
        for (int j = 1; j <= sum / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - stones[i - 1] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }
    }

    return sum - 2 * dp[stonesSize][sum / 2];
}