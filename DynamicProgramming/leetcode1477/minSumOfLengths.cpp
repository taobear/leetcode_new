#include "minSumOfLengths.h"

#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int binarySearch(int *arr, int arrSize, int target)
{
    if (arrSize <= 0) {
        return -1;
    }

    int lo = 0, hi = arrSize - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) {
            return mid;
        }else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return -1;
}

int minSumOfLengths(int* arr, int arrSize, int target)
{
    int preSum[arrSize + 1];
    preSum[0] = 0;
    for (int i = 1; i <= arrSize; i++) {
        preSum[i] = preSum[i - 1] + arr[i - 1];
    }

    int sumTarLen[arrSize + 1];
    sumTarLen[0] = INT_MAX;
    for (int i = 1; i <= arrSize; i++) {
        if (preSum[i] < target) {
            sumTarLen[i] = INT_MAX;
        } else {
            int index = binarySearch(preSum, i, preSum[i] - target);
            if (index == -1) {
                sumTarLen[i] = INT_MAX;
            } else {
                sumTarLen[i] = i - index;
            }
        }
    }

    int result = INT_MAX;
    int dpMin[arrSize + 1];
    dpMin[0] = INT_MAX;
    for (int i = 1; i <= arrSize; i++) {
        dpMin[i] = min(dpMin[i - 1], sumTarLen[i]);
        if (dpMin[i] != INT_MAX && 
            sumTarLen[i] != INT_MAX && dpMin[i - sumTarLen[i]] != INT_MAX) {
            result = min(result, sumTarLen[i] + dpMin[i - sumTarLen[i]]);
        }
    }

    return result == INT_MAX ? -1 : result;
}