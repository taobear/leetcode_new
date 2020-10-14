#include "maxSumDivThree.h"

#include <stdio.h>

void test1()
{
    int nums[] = {3, 6, 5, 1, 8};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test1(): %d\n", maxSumDivThree(nums, numsSize));
}

void test2()
{
    int nums[] = {4};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test2(): %d\n", maxSumDivThree(nums, numsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}