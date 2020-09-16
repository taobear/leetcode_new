#include "new21Game.h"

double new21Game(int N, int K, int W)
{
    int gameMaxGrade = K + W - 1;
    int dp[gameMaxGrade + 1];

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= gameMaxGrade; i++) {
        if (i <= K) {
            dp[i] = 2 * dp[i - 1];
        } else {
            dp[i] = dp[i - 1];
        }

        if (i > W) {
            dp[i] -= dp[i - W - 1];
        }
    }

    int notLargerThanN = 0;
    int notLessThanK = 0;
    for (int i = K; i <= gameMaxGrade; i++) {
        if (i <= N) {
            notLargerThanN += dp[i];
        }
        notLessThanK += dp[i];
    }

    return (float)notLargerThanN / notLessThanK;
}