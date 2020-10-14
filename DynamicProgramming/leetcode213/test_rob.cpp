#include "rob.h"

#include <stdio.h>

void test1()
{
    int nums[] = {2, 3, 2};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test1(): %d\n", rob(nums, numsSize));
}

void test2()
{
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test2(): %d\n", rob(nums, numsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}