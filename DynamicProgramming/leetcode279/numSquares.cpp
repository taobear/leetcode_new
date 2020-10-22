#include "numSquares.h"

#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int numSquares(int n)
{
    int fmin[n + 1];

    fmin[0] = 0;
    for (int i = 1; i <= n; i++) {
        fmin[i] = INT_MAX;
        for (int square = 1; square * square <= i; square++) {
            fmin[i] = min(fmin[i], fmin[i - square * square] + 1);
        }
    }

    return fmin[n];
}