#include "combinationSum3.h"

#include <stdlib.h>
#include <string.h>

void backTrack(int k, int n, int **comb, int *combNum, int *combSize, int selectStart, int *tmpComb, int level)
{
    if (k == 0 && n == 0) {
        comb[*combNum] = (int *)malloc(level * sizeof(int));
        combSize[*combNum] = level;
        memcpy(comb[*combNum], tmpComb, level * sizeof(int));
        *combNum = *combNum + 1;
    }

    if (k == 0 || n <= 0) {
        return;
    }

    for (int i = selectStart; i <= 9; i++) {
        if (i > n) {
            break;
        }

        tmpComb[level] = i;
        backTrack(k - 1, n - i, comb, combNum, combSize, i + 1, tmpComb, level + 1);
    }
}

int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes)
{
    int **comb = (int **)malloc(10000 * sizeof(int *));
    int combNum = 0;
    int *combSize = (int *)malloc(10000 * sizeof(int *));

    const int maxCombSize = 9;
    int tmpComb[maxCombSize];
    backTrack(k, n, comb, &combNum, combSize, 1, tmpComb, 0);

    *returnSize = combNum;
    *returnColumnSizes = combSize;
    return comb;
}