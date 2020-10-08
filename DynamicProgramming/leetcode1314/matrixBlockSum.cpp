#include "matrixBlockSum.h"

#include <stdlib.h>

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int K, int* returnSize, int** returnColumnSizes)
{
    int rowSize = matSize;
    int colSize = *matColSize;

    int prefixSumMat[rowSize][colSize];
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (i == 0 && j == 0) {
                prefixSumMat[i][j] = mat[i][j];
            } else if (i == 0) {
                prefixSumMat[i][j] = prefixSumMat[i][j - 1] + mat[i][j];
            } else if (j == 0) {
                prefixSumMat[i][j] = prefixSumMat[i - 1][j] + mat[i][j];
            } else {
                prefixSumMat[i][j] = prefixSumMat[i - 1][j] + prefixSumMat[i][j - 1] + mat[i][j] - prefixSumMat[i - 1][j - 1];
            }
        }
    }

    int** retMat = (int**)malloc(rowSize * sizeof(int*));
    for (int i = 0; i < rowSize; i++) {
        retMat[i] = (int*)malloc(colSize * sizeof(int));
    }

    int retMatSize = rowSize;
    int* retMatColSize = (int*)malloc(rowSize * sizeof(int));

    for (int i = 0; i < rowSize; i++) {
        int rowBeg = i - K < 0 ? 0 : i - K;
        int rowEnd = i + K < rowSize ? i + K : rowSize - 1;
        for (int j = 0; j < colSize; j++) {
            int colBeg = j - K < 0 ? 0 : j - K;
            int colEnd = j + K < colSize ? j + K : colSize - 1;
            if (rowBeg == 0 && colBeg == 0) {
                retMat[i][j] = prefixSumMat[rowEnd][colEnd];
            } else if (rowBeg == 0) {
                retMat[i][j] = prefixSumMat[rowEnd][colEnd] - prefixSumMat[rowEnd][colBeg - 1];
            } else if (colBeg == 0) {
                retMat[i][j] = prefixSumMat[rowEnd][colEnd] - prefixSumMat[rowBeg - 1][colEnd];
            } else {
                retMat[i][j] = prefixSumMat[rowEnd][colEnd] - prefixSumMat[rowEnd][colBeg - 1] - prefixSumMat[rowBeg - 1][colEnd] + prefixSumMat[rowBeg - 1][colBeg - 1];
            }
        }

        retMatColSize[i] = colSize;
    }

    *returnSize = retMatSize;
    *returnColumnSizes = retMatColSize;
    return retMat;
}