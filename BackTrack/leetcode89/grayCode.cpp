#include "grayCode.h"

#include <stdlib.h>
#include <string.h>

int *grayCode(int n, int *returnSize)
{
    int grayCodeSize = 1 << n;
    int isVisited[grayCodeSize];
    memset(isVisited, 0, grayCodeSize * sizeof(int));

    int cntGrayCode = 0;
    int curGrayCode = 0;
    int *retGrayCode = (int *)malloc(sizeof(int) * grayCodeSize);
    while (cntGrayCode < grayCodeSize) {
        for (int i = 0; i < n; ++i) {
            int tmpGrayCode2 = curGrayCode & (~(1 << i));
            if (isVisited[tmpGrayCode2] == 0) {
                curGrayCode = tmpGrayCode2;
                break;
            }

            int tmpGrayCode1 = curGrayCode | (1 << i);
            if (isVisited[tmpGrayCode1] == 0) {
                curGrayCode = tmpGrayCode1;
                break;
            }
        }
        isVisited[curGrayCode] = 1;
        retGrayCode[cntGrayCode] = curGrayCode;
        cntGrayCode++;
    }

    *returnSize = grayCodeSize;
    return retGrayCode;
}