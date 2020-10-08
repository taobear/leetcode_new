#include "subarraysWithKDistinct.h"

#include <string.h>

int atMostKDistinct(int* A, int ASize, int K)
{
    int arrCount[ASize + 1];
    memset(arrCount, 0, sizeof(int) * (ASize + 1));

    int left = 0, diff = 0;
    int ans = 0;
    for (int j = 0; j < ASize; j++) {
        if (arrCount[A[j]]++ == 0) {
            diff++;
        }

        while (diff > K) {
            if (--arrCount[A[left++]] == 0) {
                diff--;
            }
        }

        ans += j - left + 1;
    }

    return ans;
}

int subarraysWithKDistinct(int* A, int ASize, int K)
{
    return atMostKDistinct(A, ASize, K) - atMostKDistinct(A, ASize, K - 1); 
}