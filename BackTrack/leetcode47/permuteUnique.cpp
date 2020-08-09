#include "permuteUnique.h"

#include <stdlib.h>
#include <string.h>

#define MAX_PERMUTE_NUM 100000

void backTrack(int *nums, int numsSize, int **permutes, int *permutesNum, int *permutesSize, int *tmpPermute, int *visited, int level)
{
    if (level == numsSize) {
        permutes[*permutesNum] = (int *)malloc(numsSize * sizeof(int));
        memcpy(permutes[*permutesNum], tmpPermute, numsSize * sizeof(int));
        permutesSize[*permutesNum] = numsSize;
        *permutesNum = *permutesNum + 1;
        return;
    }

    for (int i = 0; i < numsSize; ++i) {
        if (visited[i] == 1) {
            continue;
        }

        if (i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) {
            continue;
        }

        visited[i] = 1;
        tmpPermute[level] = nums[i];
        backTrack(nums, numsSize, permutes, permutesNum, permutesSize, tmpPermute, visited, level + 1);
        visited[i] = 0;
    }
}

int intCompFunc(const void *a, const void *b)
{
    return *((const int*)a) - *((const int*)b);
}

int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), intCompFunc);

    int **permutes = (int **)malloc(MAX_PERMUTE_NUM * sizeof(int*));
    int permutesNum = 0;
    int *permutesSize = (int *)malloc(MAX_PERMUTE_NUM * sizeof(int));
    int *tmpPermute = (int *)malloc(numsSize * sizeof(int));
    int *isVisited = (int *)malloc(numsSize * sizeof(int));
    memset(isVisited, 0, numsSize * sizeof(int));
    
    backTrack(nums, numsSize, permutes, &permutesNum, permutesSize, tmpPermute, isVisited, 0);
    free(tmpPermute);
    free(isVisited);

    *returnSize = permutesNum;
    *returnColumnSizes = permutesSize;
    return permutes;
}