#include "findTargetSumWays.h"

#define MAX_ARRAY_NUM 20
#define MAX_ARRAY_SUM 1000

int g_sumWaysNum[MAX_ARRAY_NUM][MAX_ARRAY_SUM * 2];

int helper(int* nums, int numsSize, int S)
{
    if (numsSize <= 0) {
        return S == 0 ? 1 : 0;
    }

    int ret = 0;
    if (S + nums[numsSize - 1] < 1000) {
        if (g_sumWaysNum[numsSize - 1][S + nums[numsSize - 1] + MAX_ARRAY_SUM] == -1) {
            g_sumWaysNum[numsSize - 1][S + nums[numsSize - 1] + MAX_ARRAY_SUM] = helper(nums, numsSize - 1, S + nums[numsSize - 1]);
        }

        ret += g_sumWaysNum[numsSize - 1][S + nums[numsSize - 1] + MAX_ARRAY_SUM];
    }

    if (S - nums[numsSize - 1] > -1000) {
        if (g_sumWaysNum[numsSize - 1][S - nums[numsSize - 1] + MAX_ARRAY_SUM] == -1) {
            g_sumWaysNum[numsSize - 1][S - nums[numsSize - 1] + MAX_ARRAY_SUM] = helper(nums, numsSize - 1, S - nums[numsSize - 1]);
        }

        ret += g_sumWaysNum[numsSize - 1][S - nums[numsSize - 1] + MAX_ARRAY_SUM];
    }

    return ret;
}

int findTargetSumWays(int* nums, int numsSize, int S)
{
    if (S > MAX_ARRAY_SUM) {
        return 0;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < MAX_ARRAY_SUM * 2; j++) {
            g_sumWaysNum[i][j] = -1;
        }
    }

    return helper(nums, numsSize, S);
}