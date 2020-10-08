#include "canCross.h"

int binarySearch(int* stones, int left, int right, int target)
{
    int lo = left, hi = right;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (stones[mid] == target) {
            return mid;
        }

        if (stones[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return -1;
}

bool canCross(int* stones, int stonesSize)
{
    if (stonesSize < 2) {
        return false;
    }

    if (stones[0] != 0 || stones[1] != 1) {
        return false;
    }

    int dp[stonesSize][stonesSize];

    dp[0][0] = 0;
    dp[1][0] = 1;
    for (int i = 2; i < stonesSize; i++) {
        dp[i][0] = 0;
        for (int j = 1; j < i; j++) {
            dp[i][j] = 0;

            int k = stones[i] - stones[j];
            int lastStone = stones[j] - k;
            int index;
            if (lastStone - 1 >= 0) {
                index = binarySearch(stones, 0, j - 1, lastStone - 1);
                if (index != -1) {
                    dp[i][j] |= dp[j][index];
                }
            }

            if (lastStone >= 0) {
                index = binarySearch(stones, 0, j - 1, lastStone);
                if (index != -1) {
                    dp[i][j] |= dp[j][index];
                }
            }

            if (lastStone + 1 >= 0) {
                index = binarySearch(stones, 0, j - 1, lastStone + 1);
                if (index != -1) {
                    dp[i][j] |= dp[j][index];
                }
            }
        }
    }

    bool res = false;
    for (int i = 0; i < stonesSize - 1; i++) {
        res |= dp[stonesSize - 1][i];
    }

    return res;
}