#include "tilingRectangle.h"

#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int tilingRectangle(int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = INT_MAX;
            for (int k = 1; k < i; k++) {
                dp[i][j] = MIN(dp[k][j] + dp[i - k][j], dp[i][j]);
            }

            for (int k = 1; k < j; k++) {
                dp[i][j] = MIN(dp[i][k] + dp[i][j - k], dp[i][j]);
            }

            for (int p = 1; p < MIN(i, j); p++) {
                for (int k = 1; k < p; ++k) {
                    if (k + p >= j) {
                        continue;
                    }

                    dp[i][j] = MIN(dp[i][j], dp[p - k][j - p] +
                                             dp[i - p + k][j - p - k] +
                                             dp[i - p][p + k] + 2);
                }
            }
        }
    }

    return dp[n][m];
}