#include "minSwap.h"

#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int minSwap(int* A, int ASize, int* B, int BSize)
{
    if (ASize != BSize) {
        return -1;
    }

    if (ASize <= 1) {
        return 0;
    }

    int keep = 0;
    int swap = 1;

    for (int index = 1; index < ASize; index++) {
        int kt = INT_MAX;
        int st = INT_MAX;

        if (A[index] > A[index - 1] && B[index] > B[index - 1]) { // 都不用交换
            st = min(st, swap + 1);
            kt = min(kt, keep);
        }

        if (A[index] > B[index - 1] && B[index] > A[index - 1]) { // 可以需要交换
            kt = min(kt, swap);
            st = min(st, keep + 1);
        }

        keep = kt;
        swap = st;
    }

    return keep > swap ? swap : keep;
}