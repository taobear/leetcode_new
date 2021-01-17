#include "largestDivisibleSubset.h"

int intCompare(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize)
{
    qsort(nums, numsSize, sizeof(int), intCompare);

    int lastRec[numsSize];
    int sizeRec[numsSize];

    int maxSize = 1;
    int maxLast = 0;
    for (int i = 0; i < numsSize; i++) {
        lastRec[i] = i;
        sizeRec[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && sizeRec[j] + 1 > sizeRec[i]) {
                lastRec[i] = j;
                sizeRec[i] = sizeRec[j] + 1;
            }
        }

        if (sizeRec[i] > maxSize) {
            maxSize = sizeRec[i];
            maxLast = i;
        }
    }

    int *ret = (int *)malloc(sizeof(int) * maxSize);
    int curLast = maxLast;
    for (int i = maxSize - 1; i >= 0; i--) {
        ret[i] = nums[curLast];
        curLast = lastRec[curLast];
    }

    *returnSize = maxSize;
    return ret;
}