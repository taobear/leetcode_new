#include "trap.h"

#include <stdlib.h>

#define MAX_STACK_SIZE 10000
int g_decMonoStack[MAX_STACK_SIZE];

int trap(int *height, int heightSize)
{
    if (height == NULL || heightSize == 0) {
        return 0;
    }

    int trapWater = 0;

    int heightSum = 0;
    int stackSize = 0;
    int rightId = 0, rightMax = 0;
    int leftId = 0, leftMax = 0;

    g_decMonoStack[stackSize++] = rightId++;
    while (rightId < heightSize) {
        int rightMax = height[rightId];
        while (stackSize != 0 && height[g_decMonoStack[stackSize - 1]] < rightMax) {
            stackSize--;
        }

        if (stackSize == 0) {
            leftId = g_decMonoStack[stackSize];
            leftMax = height[g_decMonoStack[stackSize]];

            int sum = (rightId - leftId - 1) * (leftMax > rightMax ? rightMax : leftMax);
            trapWater += sum - heightSum;
            heightSum = 0;
        } else {
            heightSum += height[rightId];
        }

        g_decMonoStack[stackSize++] = rightId++;
    }

    int frontId = 0;
    leftId = g_decMonoStack[frontId];
    leftMax = height[leftId];
    while (stackSize > 1) {
        rightId = g_decMonoStack[frontId + 1];
        rightMax = height[rightId];

        int sum = (rightId - leftId - 1) * (leftMax > rightMax ? rightMax : leftMax);
        heightSum = 0;
        for (int i = leftId + 1; i < rightId; ++i) {
            heightSum += height[i];
        }

        trapWater += sum - heightSum;

        leftId = rightId;
        leftMax = rightMax;

        stackSize --;
        frontId ++;
    }

    return trapWater;
}