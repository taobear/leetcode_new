#include "minSubArrayLen.h"

#include <stdlib.h>

int minSubArrayLen(int s, int *nums, int numsSize)
{
    int curSum = 0;
    int minlen = INT_MAX;

    int i = 0;
    for (int j = 0; j < numsSize; ++j) {
        curSum += nums[j];
        while (i <= j && curSum >= s) {
            int len = j - i + 1;
            minlen = len > minlen ? minlen : len;

            curSum -= nums[i];
            i++;
        }
    }

    return minlen == INT_MAX ? 0 : minlen;
}