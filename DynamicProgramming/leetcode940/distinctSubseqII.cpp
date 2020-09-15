#include "distinctSubseqII.h"

#include <string.h>

int distinctSubseqII(char *S)
{
    int slen = strlen(S);
    int dp[slen];

    dp[0] = 1;
    for (int i = 1; i < slen; i++) {
        int count = 0;
        for (int j = 0; j < i; j++) {
            if (S[j] == S[i]) {
                continue;
            }
            
            count += dp[j];
        }

        dp[i] = count + 1;
    }

    int sumDistinct = 0;
    for (int i = 0; i < slen; i++) {
        sumDistinct += dp[i];
    }

    return sumDistinct;
}