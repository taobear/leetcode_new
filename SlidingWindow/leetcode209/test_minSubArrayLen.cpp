#include "minSubArrayLen.h"

#include <stdio.h>

void test1()
{
    int s = 7;
    int nums[] = {2, 3, 1, 2, 4, 3};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test1(): %d\n", minSubArrayLen(s, nums, numsSize));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}