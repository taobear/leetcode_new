#include "maxSubarraySumCircular.h"

#include <stdlib.h>

int maxSubarraySumCircular(int* A, int ASize)
{
    int sumAll = 0;
    int maxSum = INT_MIN, curMaxSum = INT_MIN;
    int minSum = INT_MAX, curMinSum = INT_MAX;

    for (int index = 0; index < ASize; index++) {
        sumAll += A[index];

        curMaxSum = curMaxSum > 0 ? curMaxSum + A[index] : A[index];
        curMinSum = curMinSum < 0 ? curMinSum + A[index] : A[index];

        maxSum = curMaxSum > maxSum ? curMaxSum : maxSum;
        minSum = curMinSum < minSum ? curMinSum : minSum;
    }

    return (maxSum > sumAll - minSum || sumAll - minSum == 0) ? maxSum : sumAll - minSum;
}