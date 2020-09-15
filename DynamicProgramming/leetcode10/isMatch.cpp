#include "isMatch.h"

#include <stdlib.h>
#include <string.h>

bool isMatch(char *s, char *p)
{
    int slen = strlen(s);
    int plen = strlen(p);

    int dp[slen + 1][plen + 1];
    memset(dp, 0, sizeof(int) * (slen + 1) * (plen + 1));

    dp[0][0] = 1;
    for (int j = 2; j <= plen; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    for (int i = 1; i <= slen; i++) {
        for (int j = 1; j <= plen; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                    dp[i][j] = dp[i][j - 2];
                }
                else {
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
    }

    return dp[slen][plen];
}