#include "cuttingRope.h"

#define MOD 1000000007

int cuttingRope(int n)
{
    if (n <= 3) {
        return n - 1;
    }

    if (n == 4) {
        return n;
    }

    long res = 1;
    while (n > 4) {
        res = res * 3 % MOD;
        n -= 3;
    }

    return res * n % MOD;
}