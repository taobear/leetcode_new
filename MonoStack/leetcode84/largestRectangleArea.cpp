#include "largestRectangleArea.h"

#include <stdlib.h>

#define MAX_STACK_SIZE 10000
int g_incMonoStack[MAX_STACK_SIZE];
int g_stackSize = 0;

int largestRectangleArea(int *heights, int heightsSize)
{
    if (heights == NULL || heightsSize == 0) {
        return 0;
    }

    g_stackSize = 0; // initialization

    int curRectArea = 0, maxRectArea = 0;
    int heightIndex = 0;
    while (heightIndex < heightsSize || g_stackSize != 0) {
        while (g_stackSize != 0 && 
            (heightIndex >= heightsSize || heights[g_incMonoStack[g_stackSize - 1]] > heights[heightIndex])) {
            int popId = g_incMonoStack[g_stackSize - 1];
            int topId = g_stackSize > 1 ? g_incMonoStack[g_stackSize - 2] : -1;
            int popHeight = heights[popId];

            curRectArea = popHeight * (heightIndex - topId - 1);
            maxRectArea = curRectArea > maxRectArea ? curRectArea : maxRectArea;

            g_stackSize --;
        }

        if (heightIndex < heightsSize) 
            g_incMonoStack[g_stackSize++] = heightIndex++;
    }

    return maxRectArea;
}