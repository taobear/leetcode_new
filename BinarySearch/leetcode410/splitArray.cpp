#include "splitArray.h"

#include <limits.h>
#include <stdlib.h>

long getArraySum(int *nums, int numsSize)
{
    long result = 0;
    for (int index = 0; index < numsSize; ++index) {
        result += nums[index];
    }

    return result;
}

long getArrayMin(int *nums, int numsSize)
{
    int result = INT_MAX;
    for (int index = 0; index < numsSize; ++index) {
        result = result > nums[index] ? nums[index] : result;
    }

    return result;
}

bool subArrayMaxSumExccedTarget(int *nums, int numsSize, int m, long target)
{
    if (nums == NULL || numsSize == 0) {
        return false;
    }

    long subArraySum = 0;
    int subArrayCnt = 0;
    for (int index = 0; index < numsSize; ++index) {
        if (subArraySum + nums[index] > target) {
            subArraySum = 0;
            subArrayCnt ++;
        }

        if (nums[index] > target) {
            return true;
        }

        subArraySum += nums[index];
    }

    return subArrayCnt + 1 > m;
}

int splitArray(int *nums, int numsSize, int m)
{
    long right = getArraySum(nums, numsSize);
    long left = getArrayMin(nums, numsSize);
    while (left <= right) {
        long mid = left + (right - left) / 2;
        bool isExceed = subArrayMaxSumExccedTarget(nums, numsSize, m, mid);
        if (isExceed) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}