#include "spiralOrder.h"

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP,
    DIR_DOWN,
    DIR_BOTTOM
} Direction;

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int rowsNum = matrixSize, colsNum = *matrixColSize;
    int arraySize = rowsNum * colsNum;
    int *arrayRet = (int *)malloc(arraySize * sizeof(int));

    int rowStart = 0, rowEnd = matrixSize - 1;
    int colStart = 0, colEnd = *matrixColSize - 1;

    int curIndex = 0;
    int curRow = 0, curCol = 0;
    Direction dir = DIR_RIGHT;
    while (curIndex < arraySize) {
        switch (dir) {
            case DIR_LEFT:
                while (curCol >= colStart) {
                    arrayRet[curIndex] = matrix[curRow][curCol];
                    curIndex++;
                    curCol--;
                }
                rowEnd--; 
                curRow--; curCol++;
                dir = DIR_UP;
                break;
            case DIR_RIGHT:
                while (curCol <= colEnd) {
                    arrayRet[curIndex] = matrix[curRow][curCol];
                    curIndex++;
                    curCol++;
                }
                rowStart++; 
                curRow++; curCol--;
                dir = DIR_DOWN;
                break;
            case DIR_UP:
                while (curRow >= rowStart) {
                    arrayRet[curIndex] = matrix[curRow][curCol];
                    curIndex++;
                    curRow--;
                }
                colStart++; 
                curRow++; curCol++;
                dir = DIR_RIGHT;
                break;
            case DIR_DOWN:
                while (curRow <= rowEnd) {
                    arrayRet[curIndex] = matrix[curRow][curCol];
                    curIndex++;
                    curRow++;
                }
                colEnd--; 
                curRow--; curCol--;
                dir = DIR_LEFT;
                break;
            default:
                break;
        }
    }

    *returnSize = curIndex;
    return arrayRet;
}