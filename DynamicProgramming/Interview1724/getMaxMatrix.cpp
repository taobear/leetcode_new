#include "getMaxMatrix.h"

#include <stdlib.h>
#include <string.h>

int getMaxSumArr(int *arr, int arrSize, int *start, int *end)
{
    int maxSum = INT_MIN;
    int curSum = 0;
    int curStart = 0;
    for (int index = 0; index < arrSize; index++) {
        if (curSum > 0) {
            curSum += arr[index];
        } else {
            curSum = arr[index];
            curStart = index;
        }

        if (curSum > maxSum) {
            *start = curStart;
            *end = index;
            maxSum = curSum;
        }
    }

    return maxSum;
}

int* getMaxMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int maxSum = matrix[0][0];

    int retMatSize = 4;
    int *retMat = (int *)malloc(retMatSize * sizeof(int));
    memset(retMat, 0, sizeof(int) * retMatSize);

    int rowSize = matrixSize;
    int colSize = matrixColSize[0];

    int sumArr[colSize];
    for (int i = 0; i < rowSize; i++) {
        memset(sumArr, 0, sizeof(int) * colSize);

        for (int j = i; j < rowSize; j++) {
            for (int k = 0; k < colSize; k++) {
                sumArr[k] += matrix[j][k];
            }

            int start, end, curMaxSum;
            curMaxSum = getMaxSumArr(sumArr, colSize, &start, &end);

            if (curMaxSum > maxSum) {
                maxSum = curMaxSum;

                retMat[0] = i;
                retMat[1] = start;
                retMat[2] = j;
                retMat[3] = end;
            }
        }
    }

    *returnSize = retMatSize;
    return retMat;
}