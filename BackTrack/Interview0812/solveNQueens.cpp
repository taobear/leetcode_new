#include "solveNQueens.h"

#include <string.h>
#include <stdlib.h>

#define MAX_NQUEENS_NUM 100000

bool isQueenInvalid(char **queen, int n, int row, int col)
{
    /* is col duplicate */
    for (int index = 0; index < row; ++index) {
        if (queen[index][col] == 'Q') {
            return false;
        }
    }

    int leftDignalRow = row - 1;
    int leftDignalCol = col - 1;
    while (leftDignalRow >= 0 && leftDignalCol >= 0) {
        if (queen[leftDignalRow][leftDignalCol] == 'Q') {
            return false;
        }

        leftDignalRow--;
        leftDignalCol--;
    }

    int rightDignalRow = row - 1;
    int rightDignalCol = col + 1;
    while (rightDignalRow >= 0 && rightDignalCol < n) {
        if (queen[rightDignalRow][rightDignalCol] == 'Q') {
            return false;
        }

        rightDignalRow--;
        rightDignalCol++;
    }

    return true;
}

void solveNQueens_aux(int n, char ***nQueens, int *nQueensNum, int *nQueensColNum, char **pathTrack, int pathLevel)
{
    if (pathLevel == n) {
        nQueens[*nQueensNum] = (char **)malloc(n * sizeof(char *));
        for (int index = 0; index < n; ++index) {
            nQueens[*nQueensNum][index] = (char *)malloc((n + 1) * sizeof(char));
            strcpy(nQueens[*nQueensNum][index], pathTrack[index]);
        }

        nQueensColNum[*nQueensNum] = n;
        *nQueensNum = *nQueensNum + 1;
        return;
    }

    for (int index = 0; index < n; ++index) {
        if (isQueenInvalid(pathTrack, n, pathLevel, index) != true) {
            continue;
        }

        pathTrack[pathLevel][index] = 'Q';
        solveNQueens_aux(n, nQueens, nQueensNum, nQueensColNum, pathTrack, pathLevel + 1);
        pathTrack[pathLevel][index] = '.';
    }
}

char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
    char **pathTrack = (char **)malloc(n * sizeof(char*));
    for (int index = 0; index < n; ++index) {
        pathTrack[index] = (char *)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; ++j) {
            pathTrack[index][j] = '.';
        }
        pathTrack[index][n] = '\0';
    }

    char ***nQueens = (char ***)malloc(MAX_NQUEENS_NUM * sizeof(char **));
    int *nQueensColNum = (int *)malloc(MAX_NQUEENS_NUM * sizeof(int));
    int nQueensNum = 0;
    solveNQueens_aux(n, nQueens, &nQueensNum, nQueensColNum, pathTrack, 0);

    for (int index = 0; index < n; ++index) {
        free(pathTrack[index]);
    }
    free(pathTrack);

    *returnSize = nQueensNum;
    *returnColumnSizes = nQueensColNum;
    return nQueens;
}
