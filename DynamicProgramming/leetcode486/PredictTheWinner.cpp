#include "PredictTheWinner.h"

int helper(int *nums, int L, int R)
{
    if (L == R) {
        return nums[L];
    }

    int leftChoose = nums[L] - helper(nums, L + 1, R);
    int rightChoose = nums[R] - helper(nums, L, R - 1);

    return leftChoose > rightChoose ? leftChoose : rightChoose;
}

bool PredictTheWinner(int* nums, int numsSize)
{
    return helper(nums, 0, numsSize - 1) >= 0;
}