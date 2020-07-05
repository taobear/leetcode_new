#include "maxProduct.h"

#include <stdlib.h>

int maxProduct(int *nums, int numsSize)
{
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    
    int result = nums[0];
    int minMost = nums[0];
    int maxMost = nums[0];
    int maxMostTmp = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] >= 0) {
            maxMost = maxMost * nums[i] > nums[i] ? maxMost * nums[i] : nums[i];
            minMost = minMost * nums[i] < nums[i] ? minMost * nums[i] : nums[i];
        } else {
            maxMostTmp = minMost * nums[i] > nums[i] ? minMost * nums[i] : nums[i];
            minMost = maxMost * nums[i] < nums[i] ? maxMost * nums[i] : nums[i];
            maxMost = maxMostTmp;
        }

        result = maxMost > result ? maxMost : result;
    }

    return result;
}