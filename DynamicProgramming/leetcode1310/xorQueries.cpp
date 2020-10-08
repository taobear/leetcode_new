#include "xorQueries.h"

#include <stdlib.h>

int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    int dp[arrSize + 1];
    dp[0] = 0;

    for (int i = 0; i < arrSize; i++) {
        dp[i + 1] = dp[i] ^ arr[i];
    }

    int *result = (int *)malloc(queriesSize * sizeof(int));
    for (int i = 0; i < queriesSize; i++) {
        if (queriesColSize[i] != 2) {
            *returnSize = 0;
            free(result);
            return NULL;
        }
        
        int L = queries[i][0];
        int R = queries[i][1];
        result[i] = dp[R + 1] ^ dp[L];
    }

    *returnSize = queriesSize;
    return result;
}