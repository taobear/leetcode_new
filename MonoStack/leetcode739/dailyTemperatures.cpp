#include "dailyTemperatures.h"

#include <stdlib.h>

#define MAX_STACK_SIZE 100000
int g_decMonoStack[MAX_STACK_SIZE];
int g_stackSize = 0;

int *dailyTemperatures(int *T, int TSize, int *returnSize)
{
    if (T == NULL || TSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int *)malloc(TSize * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = TSize;
    for (int i = 0; i < TSize; ++i) {
        result[i] = 0;
    }

    g_stackSize = 0;
    for (int i = 0; i < TSize; ++i) {
        while (g_stackSize != 0 && T[g_decMonoStack[g_stackSize - 1]] < T[i]) {
            result[g_decMonoStack[g_stackSize - 1]] = i - g_decMonoStack[g_stackSize - 1];
            g_stackSize--;
        }
        g_decMonoStack[g_stackSize++] = i;
    }

    return result;
}