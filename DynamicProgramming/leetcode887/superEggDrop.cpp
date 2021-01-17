#include "superEggDrop.h"

#include <stdlib.h>

int max(int a, int b)
{
    return a < b ? b : a;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int superEggDrop(int K, int N)
{
    int dp[N + 1][K + 1];

    for (int X = 0; X <= N; X++) {
        dp[X][1] = X;
    }

    for (int k = 1; k <= K; k++) {
        dp[0][k] = 0;
        dp[1][k] = 1;
    }

    for (int n = 2; n <= N; n++) {
        for (int k = 2; k <= K; k++) {
            dp[n][k] = INT_MAX;

            int lo = 1, hi = n;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                int t1 = dp[mid - 1][k - 1];
                int t2 = dp[n - mid][k];
                if (t1 > t2) {
                    hi = mid - 1;
                    dp[n][k] = min(dp[n][k], t1 + 1);
                } else {
                    lo = mid + 1;
                    dp[n][k] = min(dp[n][k], t2 + 1);
                }
            }
        }
    }

    return dp[N][K];
}