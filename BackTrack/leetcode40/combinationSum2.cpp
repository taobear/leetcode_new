#include "combinationSum2.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_SUBSET_NUM 1000000

int intComp(const void *a, const void *b)
{
    return *((const int *)a) - *((const int *)b);
}

void backTrack(int *candidates, int candidatesSize, int target,
               int **subset, int *subsetNum, int *subsetSize, 
               int *trackPath, int pathLevel, int start)
{
    if (target == 0) {
        subset[*subsetNum] = (int *)malloc(sizeof(int) * (pathLevel));
        memcpy(subset[*subsetNum], trackPath, pathLevel * sizeof(int));
        subsetSize[*subsetNum] = pathLevel;
        *subsetNum = *subsetNum + 1;
        return;
    }

    for (int index = start; index < candidatesSize; ++index) {
        if (index != start && candidates[index - 1] == candidates[index]) {
            continue;
        }

        if (target < candidates[index]) {
            break;
        }

        trackPath[pathLevel] = candidates[index];
        backTrack(candidates, candidatesSize, target - candidates[index], 
                  subset, subsetNum, subsetSize, trackPath, pathLevel + 1, index + 1);
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    if (target == 0 || candidatesSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(candidates, candidatesSize, sizeof(int), intComp);

    int **subset = (int **)malloc(sizeof(int *) * MAX_SUBSET_NUM);
    int *subsetSize = (int *)malloc(sizeof(int) * MAX_SUBSET_NUM);
    int subsetNum;
    int *trackPath = (int *)malloc(sizeof(int) * candidatesSize);
    backTrack(candidates, candidatesSize, target, subset, &subsetNum, subsetSize, trackPath, 0, 0);

    *returnSize = subsetNum;
    *returnColumnSizes = subsetSize;
    free(trackPath);

    return subset;
}