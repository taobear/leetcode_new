#include "findCheapestPrice.h"

#include <stdlib.h>

#define PING_PONG 2

int min(int a, int b)
{
    return a < b ? a : b;
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K)
{
    int dp[PING_PONG][n];
    for (int i = 0; i < n; i++) {
        dp[0][i] = INT_MAX;
        dp[1][i] = INT_MAX;
    }

    dp[1][src] = 0;
    for (int i = 0; i <= K; i++) {
        int currBuf = i & 1;
        int prevBuf = !currBuf;
        for (int j = 0; j < flightsSize; j++) {
            int srcTmp = flights[j][0];
            int dstTmp = flights[j][1];
            int prcTmp = flights[j][2];
            if (dp[prevBuf][srcTmp] == INT_MAX) {
                continue;
            }

            dp[currBuf][dstTmp] = min(dp[currBuf][dstTmp], dp[prevBuf][srcTmp] + prcTmp);
        }

        dp[currBuf][dst] = min(dp[prevBuf][dst], dp[currBuf][dst]);
    }

    return dp[K & 1][dst] == INT_MAX ? -1 : dp[K & 1][dst];
}