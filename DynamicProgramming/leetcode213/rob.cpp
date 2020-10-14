#include "rob.h"

int max(int a, int b)
{
    return a < b ? b : a;
}

int rob(int* nums, int numsSize)
{
    if (numsSize < 1) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    int result = max(nums[0], nums[1]);

    int dp1[numsSize]; // 偷窃第一所房子
    dp1[0] = nums[0];
    dp1[1] = 0;
    for (int i = 2; i < numsSize - 1; i++) {
        dp1[i] = 0;
        for (int j = 0; j <= i - 2; j++) {
            dp1[i] = max(dp1[i], dp1[j] + nums[i]);
        }

        result = max(dp1[i], result);
    }

    int dp2[numsSize]; // 不偷窃第一所房子
    dp2[0] = 0;
    dp2[1] = nums[1];
    for (int i = 2; i < numsSize; i++) {
        dp2[i] = 0;
        for (int j = 0; j <= i - 2; j++) {
            dp2[i] = max(dp2[i], dp2[j] + nums[i]);
        }

        result = max(dp2[i], result);
    }

    return result;
}