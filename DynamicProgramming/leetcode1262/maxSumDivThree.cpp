#include "maxSumDivThree.h"

int maxSumDivThree(int* nums, int numsSize)
{
    int maxSumMod[3] = {0, -1, -1};
    for (int i = 0; i < numsSize; i++) {
        int sumMod[3] = {maxSumMod[0], maxSumMod[1], maxSumMod[2]};
        for (int j = 0; j < 3; j++) {
            if (sumMod[j] == -1) {
                continue;
            }

            int k = (j + nums[i] % 3) % 3;
            maxSumMod[k] = sumMod[j] + nums[i] > maxSumMod[k] ? sumMod[j] + nums[i] : maxSumMod[k];
        }
    }

    return maxSumMod[0];
}
