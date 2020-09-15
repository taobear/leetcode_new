#include "countPalindromicSubsequences.h"

#include <string.h>

int countPalindromicSubsequences(char * S)
{
    int slen = strlen(S);
    int dp[slen][slen];

    for (int i = 0; i < slen; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i < slen; i++) {
        dp[i][i - 1] = 0;
    }

    for (int len = 2; len <= slen; len++) {
        for (int i = 0; i < slen - len + 1; i++) {
            int j = i + len - 1;
            if (S[i] != S[j]) {
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            } else {
                dp[i][j] = dp[i + 1][j - 1] * 2;
                int lo = i + 1, hi = j - 1;
                while (lo <= hi && S[lo] != S[i]) lo++;
                while (lo <= hi && S[hi] != S[i]) hi--;
                if (lo > hi) { // 其间没有相同元素
                    dp[i][j] += 2;
                } else if (lo == hi) { // 其间只有一个相同元素
                    dp[i][j] += 1;
                } else { // 其间有两个以上相同元素
                    dp[i][j] -= dp[lo + 1][hi - 1];
                }
            }

            dp[i][j] = (dp[i][j] % 1000000007 + 1000000007) % 1000000007;
        }
    }

    return dp[0][slen - 1];
}