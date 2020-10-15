#include "ways.h"

#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

int ways(char** pizza, int pizzaSize, int k)
{
    if (pizzaSize == 0 || pizza[0] == NULL) {
        return 0;
    }

    int rows = pizzaSize;
    int cols = strlen(pizza[0]);
    int maxSumMat[rows + 1][cols + 1];
    for (int i = 0; i <= rows; i++) {
        maxSumMat[i][0] = 0;
    }
    for (int j = 0; j <= cols; j++) {
        maxSumMat[0][j] = 0;
    }

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            maxSumMat[i][j] = pizza[i - 1][j - 1] == 'A' ? 1 : 0;
            maxSumMat[i][j] += maxSumMat[i - 1][j] + maxSumMat[i][j - 1] - maxSumMat[i - 1][j - 1];
        }
    }

    int dp[k][rows][cols];
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (maxSumMat[rows][cols] - maxSumMat[rows][j] - maxSumMat[i][cols] + maxSumMat[i][j] > 0) {
                dp[0][i][j] = 1;
            } else {
                dp[0][i][j] = 0;
            }
        }
    }

    for (int h = 1; h < k; h++) {
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                dp[h][i][j] = 0;
                for (int x = i + 1; x < rows; x++) {
                    if (maxSumMat[x][cols] - maxSumMat[x][j] - maxSumMat[i][cols] + maxSumMat[i][j] > 0) {
                        dp[h][i][j] = (dp[h][i][j] + dp[h - 1][x][j]) % MOD;
                    }
                }

                for (int y = j + 1; y < cols; y++) {
                    if (maxSumMat[rows][y] - maxSumMat[i][y] - maxSumMat[rows][j] + maxSumMat[i][j] > 0) {
                        dp[h][i][j] = (dp[h][i][j] + dp[h - 1][i][y]) % MOD;
                    }
                }
            }
        }
    }

    return dp[k - 1][0][0];
}
