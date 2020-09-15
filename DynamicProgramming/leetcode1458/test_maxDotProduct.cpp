#include "maxDotProduct.h"

#include <stdio.h>

void test1()
{
    int nums1[] = {2, 1, -2, 5};
    int nums2[] = {3, 0, -6};

    int nums1Size = sizeof(nums1) / sizeof(*nums1);
    int nums2Size = sizeof(nums2) / sizeof(*nums2);

    printf("test1(): %d\n", maxDotProduct(nums1, nums1Size, nums2, nums2Size));
}

void test2()
{
    int nums1[] = {3, -2};
    int nums2[] = {2, -6, 7};

    int nums1Size = sizeof(nums1) / sizeof(*nums1);
    int nums2Size = sizeof(nums2) / sizeof(*nums2);

    printf("test2(): %d\n", maxDotProduct(nums1, nums1Size, nums2, nums2Size));
}

void test3()
{
    int nums1[] = {-1, -1};
    int nums2[] = {1, 1};

    int nums1Size = sizeof(nums1) / sizeof(*nums1);
    int nums2Size = sizeof(nums2) / sizeof(*nums2);

    printf("test2(): %d\n", maxDotProduct(nums1, nums1Size, nums2, nums2Size));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}