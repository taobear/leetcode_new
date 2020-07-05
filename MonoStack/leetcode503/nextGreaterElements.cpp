#include "nextGreaterElements.h"

#include <stdlib.h>

#define MAX_STACK_SIZE 100000
int g_decMonoStack[MAX_STACK_SIZE];
int g_stackSize = 0;

int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *elems = (int *)malloc(numsSize * sizeof(int));
    if (elems == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize;
    for (int i = 0; i < numsSize; ++i) {
        elems[i] = -1;
    }

    g_stackSize = 0;
    for (int i = 0; i < numsSize * 2; ++i) {
        int numId = i >= numsSize ? (i - numsSize) : i;
        while (g_stackSize != 0 && nums[g_decMonoStack[g_stackSize - 1]] < nums[numId]) {
            elems[g_decMonoStack[g_stackSize - 1]] = nums[numId];
            g_stackSize--;
        }

        g_decMonoStack[g_stackSize++] = numId;
    }

    return elems;
}