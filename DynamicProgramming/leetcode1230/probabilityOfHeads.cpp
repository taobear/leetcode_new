#include "probabilityOfHeads.h"

double probabilityOfHeads(double* prob, int probSize, int target)
{
    double dp[probSize + 1][target + 1];

    dp[0][0] = 1;
    for (int i = 1; i <= probSize; i++) {
        for (int j = 0; j <= target && j <= i; j++) {
            dp[i][j] = 0;
            
            if (j - 1 >= 0) {
                dp[i][j] += dp[i - 1][j - 1] * prob[i - 1];
            }
            
            if (i - 1 >= j) {
                dp[i][j] += dp[i - 1][j] * (1. - prob[i - 1]);
            }
        }
    }

    return dp[probSize][target];
}