#include "coinChange.h"

#include <stdlib.h>

int coinChange(int* coins, int coinSize, int amount)
{
    int dp[amount + 1];
    
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < coinSize; j++) {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount] != INT_MAX ? dp[amount] : -1;
}