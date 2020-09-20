#include "leastOpsExpressTarget.h"

int min(int a, int b)
{
    return a < b ? a : b;
}

int leastOpsExpressTarget(int x, int target)
{
    if (target == 0) {
        return 0;
    }

    if (target < x) {
        return min(target * 2 - 1, 2 * (x - target));
    }
    
    int p = 0;
    long long curr = 1;
    while (curr <= target) {
        curr *= x;
        p += 1;
    }

    long long prev = curr / x;
    int pp = p - 1;

    int res = (target - prev) != 0 ? (leastOpsExpressTarget(x, target - prev) + pp) : (pp - 1);
    if (curr - target < target) {
        res = min(res, (curr - target) != 0 ? (leastOpsExpressTarget(x, curr - target) + p) : (p - 1)); // 拼成 curr 需要 p 个
    }

    return res;
}