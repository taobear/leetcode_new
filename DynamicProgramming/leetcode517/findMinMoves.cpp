#include "findMinMoves.h"

int abs(int x)
{
    return x < 0 ? -x : x;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

int findMinMoves(int* machines, int machinesSize)
{
    if (machinesSize == 0) {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < machinesSize; i++) {
        sum += machines[i];
    }

    if (sum % machinesSize != 0) {
        return -1;
    }

    int avg = sum / machinesSize;
    int res = 0, curSum = 0;
    for (int i = 0; i < machinesSize; i++) {
        int leftSize = i, rightSize = machinesSize - i - 1;

        int L = leftSize * avg - curSum;
        int R = rightSize * avg - (sum - curSum - machines[i]);
        if (L > 0 && R > 0) {
            res = max(res, L + R);
        } else {
            res = max(res, max(abs(L), abs(R)));
        }

        curSum += machines[i];
    }

    return res;
}