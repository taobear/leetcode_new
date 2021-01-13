#include "lengthOfLIS.h"

#include <stdio.h>

void test1()
{
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test1(): %d\n", lengthOfLIS(nums, numsSize));
}

void test2()
{
    int nums[] = {0, 1, 0, 3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test2(): %d\n", lengthOfLIS(nums, numsSize));
}

void test3()
{
    int nums[] = {7, 7, 7, 7, 7, 7, 7};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test3(): %d\n", lengthOfLIS(nums, numsSize));
}

void test4()
{
    int nums[] = {10, 9, 2, 5, 3, 4};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test4(): %d\n", lengthOfLIS(nums, numsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}