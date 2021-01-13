#include "lengthOfLIS.h"

int findLowerPos(int* nums, int lo, int hi, int target)
{
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return lo - 1;
}

int lengthOfLIS(int* nums, int numsSize)
{
    if (numsSize == 0) {
        return 0;
    }

    int len = 1;
    int minEnd[numsSize + 1];

    minEnd[0] = -1, minEnd[1] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > minEnd[len]) {
            minEnd[++len] = nums[i];
        } else {
            int lowPos = findLowerPos(minEnd, 1, len, nums[i]);
            minEnd[lowPos + 1] = nums[i];
        }
    }

    return len;
}