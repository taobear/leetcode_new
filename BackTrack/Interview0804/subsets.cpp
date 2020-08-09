#include "subsets.h"

#include <string.h>
#include <stdlib.h>

#define MAX_SUBSETS_NUM 100000

void backTrack(int *nums, int numsSize, int **subsets, int *subsetsNum, int *subsetsSize, int *tmpSubset, int tmpSize, int start)
{
    if (start > numsSize) {
        return;
    }

    // push back
    if (tmpSize == 0) {
        subsets[*subsetsNum] = NULL;
    } else {
        subsets[*subsetsNum] = (int *)malloc(tmpSize * sizeof(int));
        memcpy(subsets[*subsetsNum], tmpSubset, tmpSize * sizeof(int));
    }
    subsetsSize[*subsetsNum] = tmpSize;
    *subsetsNum = *subsetsNum + 1;

    for (int index = start; index < numsSize; ++index) {
        if (index != start && nums[index] == nums[index - 1]) {
            continue;
        }

        tmpSubset[tmpSize] = nums[index];
        backTrack(nums, numsSize, subsets, subsetsNum, subsetsSize, tmpSubset, tmpSize + 1, index + 1);
    }
}

int intCompFunc(const void *a, const void *b) 
{
    return *((const int *)a) - *((const int *)b);
}

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), intCompFunc);

    int **retSubsets = (int **)malloc(MAX_SUBSETS_NUM * sizeof(int *));
    int *retSubsetsSize = (int *)malloc(MAX_SUBSETS_NUM * sizeof(int));
    int retSubsetsNum = 0;

    int *tmpSubset = (int *)malloc(numsSize * sizeof(int));
    backTrack(nums, numsSize, retSubsets, &retSubsetsNum, retSubsetsSize, tmpSubset, 0, 0);

    *returnSize = retSubsetsNum;
    *returnColumnSizes = retSubsetsSize;
    return retSubsets;
}