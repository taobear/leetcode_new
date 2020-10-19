#include "getLengthOfOptimalCompression.h"

#include <stdlib.h>
#include <string.h>

int getMinCost(int num)
{
    if (num <= 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else if (num < 10) {
        return 2;
    } else if (num < 100) {
        return 3;
    } else if (num < 1000) {
        return 4;
    } else if (num < 10000) {
        return 5;
    }

    return -1;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int getLengthOfOptimalCompression(char* s, int k)
{
    int slen = strlen(s);
    int fmin[slen + 1][k + 1];

    fmin[0][0] = 0;
    for (int i = 1; i <= slen; i++) {
        for (int j = 0; j <= min(i, k); j++) { // 删除字符个数
            fmin[i][j] = INT_MAX;
            if (j > 0) {
                fmin[i][j] = fmin[i - 1][j - 1];
            }

            int diff = 0, same = 0;
            for (int x = i; x >= 1 && diff <= j; x--) {
                if (s[i - 1] == s[x - 1]) {
                    ++same;
                    if (x - 1 >= j - diff) {
                        fmin[i][j] = min(fmin[i][j], fmin[x - 1][j - diff] + getMinCost(same));
                    }
                } else {
                    ++diff;
                }
            }
        }
    }

    return fmin[slen][k];
}