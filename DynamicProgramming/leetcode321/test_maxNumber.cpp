#include "maxNumber.h"

#include <stdio.h>
#include <stdlib.h>

void print_1d_nums(int* nums, int numsSize)
{
    printf("[");
    for (int i = 0; i < numsSize - 1; ++i) {
        printf("%d, ", nums[i]);
    }

    printf("%d]\n", nums[numsSize - 1]);
}

void test1()
{
    int nums1[] = {3, 4, 6, 5};
    int nums1Size = sizeof(nums1) / sizeof(*nums1);

    int nums2[] = {9, 1, 2, 5, 8, 3};
    int nums2Size = sizeof(nums2) / sizeof(*nums2);

    int k = 5;

    int retSize = 0;
    int *ret = maxNumber(nums1, nums1Size, nums2, nums2Size, k, &retSize);

    printf("test1(): ");
    print_1d_nums(ret, retSize);

    free(ret);
}

void test2()
{
    int nums1[] = {6, 7};
    int nums1Size = sizeof(nums1) / sizeof(*nums1);

    int nums2[] = {6, 0, 4};
    int nums2Size = sizeof(nums2) / sizeof(*nums2);

    int k = 5;

    int retSize = 0;
    int *ret = maxNumber(nums1, nums1Size, nums2, nums2Size, k, &retSize);

    printf("test2(): ");
    print_1d_nums(ret, retSize);

    free(ret);
}

void test3()
{
    int nums1[] = {3, 9};
    int nums1Size = sizeof(nums1) / sizeof(*nums1);

    int nums2[] = {8, 9};
    int nums2Size = sizeof(nums2) / sizeof(*nums2);

    int k = 3;

    int retSize = 0;
    int *ret = maxNumber(nums1, nums1Size, nums2, nums2Size, k, &retSize);

    printf("test3(): ");
    print_1d_nums(ret, retSize);

    free(ret);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}