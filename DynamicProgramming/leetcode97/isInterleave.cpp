#include "isInterleave.h"

bool isInterleave(char* s1, char* s2, char* s3)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    if (len1 + len2 != len3) {
        return false;
    }

    int dp[len1 + 1][len2 + 1];
    dp[0][0] = true;
    for (int i = 1; i <= len1; i++) {
        dp[i][0] = s1[i - 1] == s3[i - 1] ? dp[i - 1][0] : false;
    }

    for (int j = 1; j <= len2; j++) {
        dp[0][j] = s2[j - 1] == s3[j - 1] ? dp[0][j - 1] : false;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            dp[i][j] = false;
            if (s1[i - 1] == s3[i + j - 1]) {
                dp[i][j] |= dp[i - 1][j];
            }

            if (s2[j - 1] == s3[i + j - 1]) {
                dp[i][j] |= dp[i][j - 1];
            }
        }
    }

    return dp[len1][len2];
}