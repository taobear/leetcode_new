#include "minDistance.h"

#include <string.h>

int max(int a, int b)
{
    return a < b ? b : a;
}

int minDistance(char* word1, char* word2)
{
    int wl1 = strlen(word1);
    int wl2 = strlen(word2);

    int dp[wl1 + 1][wl2 + 1];
    
    dp[0][0] = 0;
    for (int i = 0; i <= wl1; i++) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= wl2; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= wl1; i++) {
        for (int j = 1; j <= wl2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return wl1 + wl2 - dp[wl1][wl2] * 2;
}