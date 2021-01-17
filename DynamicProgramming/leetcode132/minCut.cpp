#include "minCut.h"

#include <string.h>
#include <stdlib.h>

bool checkPalindrome(char *s, int lo, int hi)
{
    while (lo < hi) {
        if (s[lo] != s[hi]) {
            return false;
        }

        lo++;
        hi--;
    }

    return true;
}

int minCut(char* s)
{
    int slen = strlen(s);
    if (slen <= 1) {
        return 0;
    }

    int result = INT_MAX;

    bool isPalindrome[slen][slen];
    for (int l = 1; l <= slen; l++) {
        for (int i = 0; i + l <= slen; i++) {
            int j = i + l - 1;
            if (s[i] == s[j]) {
                isPalindrome[i][j] = i + 1 <= j - 1 ? isPalindrome[i + 1][j - 1] : true;
            } else {
                isPalindrome[i][j] = false;
            }
        }
    }

    int dp[slen];

    dp[0] = 0;
    for (int i = 0; i < slen; i++) {
        if (isPalindrome[0][i]) {
            dp[i] = 0;
            continue;
        }

        dp[i] = INT_MAX;
        for (int j = 1; j <= i; j++) {
            if (!isPalindrome[j][i]) {
                continue;
            }

            dp[i] = dp[j - 1] + 1 < dp[i] ? dp[j - 1] + 1 : dp[i];
        }
    }

    return dp[slen - 1];
}