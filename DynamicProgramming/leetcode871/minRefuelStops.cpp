#include "minRefuelStops.h"

#include <stdlib.h>
#include <string.h>

long long max(long long a, long long b)
{
    return a < b ? b : a;
}

int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize)
{
    long long dp[stationsSize + 1]; // 表示加 i 次油最多加多少油

    memset(dp, 0xFF, sizeof(long long) * (stationsSize + 1));

    dp[0] = startFuel;
    for (int i = 0; i < stationsSize; i++) {
        for (int j = i; j >= 0; j--) {
            if (dp[j] < stations[i][0]) { // 加不了本次
                continue;
            }

            dp[j + 1] = max(dp[j + 1], dp[j] + (long long)stations[i][1]);
        }
    }

    for (int i = 0; i <= stationsSize; i++) {
        if (dp[i] >= target) {
            return i;
        }
    }

    return -1;
}