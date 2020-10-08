#include "numSubarrayBoundedMax.h"

int numSubarrayBoundedMax(int* A, int ASize, int L, int R)
{
    int curL = 0, curR = 0;
    int sumL = 0, sumR = 0;
    int lastMoreL = -1, lastMoreR = -1;
    for (int j = 0; j < ASize; j++) {
        if (A[j] > R) {
            curL = 0;
            curR = 0;
            lastMoreL = j;
            lastMoreR = j;
        } else if (A[j] >= L) {
            curL = 0;
            lastMoreL = j;
            curR = j - lastMoreR;
        } else {
            curL = j - lastMoreL;
            curR = j - lastMoreR;
        }

        sumL += curL;
        sumR += curR;
    }

    return sumR - sumL;
}