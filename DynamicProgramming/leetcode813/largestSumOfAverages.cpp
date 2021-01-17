#include "largestSumOfAverages.h"

double max(double a, double b) 
{
    return a < b ? b : a;
}

double largestSumOfAverages(int* A, int ASize, int K)
{
    double prefixSum[ASize + 1];
    
    prefixSum[0] = 0;
    for (int i = 1; i <= ASize; i++) {
        prefixSum[i] = prefixSum[i - 1] + A[i - 1];
    }

    double dp[ASize + 1][K];
    for (int i = 1; i <= ASize; i++) {
        dp[i][0] = prefixSum[i] / (double)i;
    }

    for (int i = 1; i <= ASize; i++) {
        for (int k = 1; k < i && k < K; k++) { // 分隔 k 次
            dp[i][k] = 0;
            for (int j = k; j < i; j++) {
                dp[i][k] = max(dp[i][k], dp[j][k - 1] + (prefixSum[i] - prefixSum[j]) / double(i - j));
            }
        }
    }

    return dp[ASize][K - 1];
}