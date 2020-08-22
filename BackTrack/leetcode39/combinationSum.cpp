#include "combinationSum.h"

#include <stdlib.h>
#include <string.h>

void backTrack(int *candidates, int candidatesSize, int target, int **comb, int *combNum, int *combSize, int *tmpComb, int level, int start)
{
    if (target == 0)
    {
        comb[*combNum] = (int *)malloc(level * sizeof(int));
        memcpy(comb[*combNum], tmpComb, level * sizeof(int));
        combSize[*combNum] = level;
        *combNum = *combNum + 1;
        return;
    }

    for (int index = start; index < candidatesSize; index++)
    {
        if (candidates[index] > target)
        {
            break;
        }

        tmpComb[level] = candidates[index];
        backTrack(candidates, candidatesSize, target - candidates[index], comb, combNum, combSize, tmpComb, level + 1, index);
    }
}

int intCompFunc(const void *a, const void *b)
{
    return *((const int *)a) - *((const int *)b);
}

#define MAX_COMB_NUM 1000
int g_tmpComb[MAX_COMB_NUM];

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), intCompFunc);

    int **comb = (int **)malloc(MAX_COMB_NUM * sizeof(int *));
    int *combSize = (int *)malloc(MAX_COMB_NUM * sizeof(int));
    int combNum = 0;

    backTrack(candidates, candidatesSize, target, comb, &combNum, combSize, g_tmpComb, 0, 0);

    *returnSize = combNum;
    *returnColumnSizes = combSize;
    return comb;
}