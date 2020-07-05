#include "threeSum.h"

#include <stdlib.h>
#include <stdio.h>

#define MAX_RETURN_ARRAY_SIZE 10000
int *g_retArrayPtr[MAX_RETURN_ARRAY_SIZE];
int g_retArraySize = 0;

int compare(const void *a, const void *b)
{
    return (*(const int*)a - *(const int*)b);
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    if (nums == NULL || numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }

    g_retArraySize = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    for (int first = 0; first < numsSize; ++first) {
        if (first > 0 && nums[first] == nums[first - 1]) {
            continue;
        }

        if (nums[first] > 0) {
            break;
        }

        int second = first + 1;
        int third = numsSize - 1;
        int target = -nums[first];
        while (second < third) {
            int twoSum = nums[second] + nums[third];
            if (twoSum < target) {
                second++;
            } else if (twoSum > target) {
                third--;
            } else {
                g_retArrayPtr[g_retArraySize] = (int*)malloc(sizeof(int) * 3); // 暂时不考虑分配失败
                g_retArrayPtr[g_retArraySize][0] = nums[first];
                g_retArrayPtr[g_retArraySize][1] = nums[second];
                g_retArrayPtr[g_retArraySize][2] = nums[third];
                g_retArraySize++;

                while (++second < third && nums[second - 1] == nums[second]);
                while (--third > second && nums[third + 1] == nums[third]);
            }
        }
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * g_retArraySize);
    for (int i = 0; i < g_retArraySize; ++i) {
        (*returnColumnSizes)[i] = 3;
    }

    int **retArray = (int **)malloc(sizeof(int*) * g_retArraySize);
    *returnSize = g_retArraySize;
    for (int i = 0; i < g_retArraySize; ++i) {
        retArray[i] = g_retArrayPtr[i];
    }

    return retArray;
}