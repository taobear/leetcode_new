#include "kConcatenationMaxSum.h"

#define MOD 1000000007

int max(int a, int b)
{
    return a < b ? b : a;
}

int getMaxSum(int* arr, int arrSize, int* curr)
{
    int maxSum = max(0, *curr);
    for (int i = 0; i < arrSize; i++) {
        if (*curr < 0) {
            *curr = arr[i];
        } else {
            *curr += arr[i];
        }

        *curr = *curr % MOD;
        maxSum = max(maxSum, *curr) % MOD;
    }

    return maxSum;
}

int kConcatenationMaxSum(int* arr, int arrSize, int k)
{
    long long sum = 0;
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
        sum %= MOD;
    }

    int result = sum > 0 ? (sum * k) % MOD : 0;

    int curr = 0;
    result = max(result, getMaxSum(arr, arrSize, &curr));

    curr = max(curr + sum * (k - 2) % MOD, curr);
    curr = max(sum * (k - 2) % MOD, curr);
    curr = max(0, curr);

    if (k >= 2) {
        result = max(result, getMaxSum(arr, arrSize, &curr));
    }

    return result;
}
