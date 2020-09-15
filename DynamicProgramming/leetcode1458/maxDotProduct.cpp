#include "maxDotProduct.h"

#include <limits.h>

#define NUM_MIN -10000

int maxDotProduct(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int dp[nums1Size + 1][nums2Size + 1];

    dp[0][0] = NUM_MIN;
    for (int i = 1; i <= nums1Size; i++) {
        dp[i][0] = NUM_MIN;
    }

    for (int j = 1; j <= nums2Size; j++) {
        dp[0][j] = NUM_MIN;
    }

    for (int i = 1; i <= nums1Size; i++) {
        for (int j = 1; j <= nums2Size; j++) {
            int maxProduct = NUM_MIN;

            int product = nums1[i - 1] * nums2[j - 1];
            maxProduct = maxProduct > product ? maxProduct : product;
            maxProduct = maxProduct > (dp[i - 1][j - 1] + product) ? maxProduct : (dp[i - 1][j - 1] + product);
            maxProduct = maxProduct > dp[i][j - 1] ? maxProduct : dp[i][j - 1];
            maxProduct = maxProduct > dp[i - 1][j] ? maxProduct : dp[i - 1][j];
            maxProduct = maxProduct > dp[i - 1][j - 1] ? maxProduct : dp[i - 1][j - 1];
            
            dp[i][j] = maxProduct;
        }
    }

    return dp[nums1Size][nums2Size];
}