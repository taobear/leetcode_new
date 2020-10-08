#include "maximumSum.h"

#include <stdlib.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int maximumSum(int* arr, int arrSize)
{
    int f[arrSize]; // 连续子数组的最大和
    int g[arrSize]; // 删除一个元素的最大和

    f[0] = arr[0];
    g[0] = 0;
    int retMaxSum = arr[0];
    for (int i = 1; i < arrSize; i++) {
        f[i] = MAX(f[i - 1] + arr[i], arr[i]);
        g[i] = MAX(g[i - 1] + arr[i], f[i - 1]);
        retMaxSum = MAX(f[i], retMaxSum);
        retMaxSum = MAX(g[i], retMaxSum);
    }

    return retMaxSum;
}