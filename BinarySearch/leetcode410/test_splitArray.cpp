#include "splitArray.h"

#include <stdio.h>

void test1()
{
    int nums[] = {7, 2, 5, 10, 8};
    int numsSize = sizeof(nums) / sizeof(*nums);
    int m = 2;

    printf("test1(): %d\n", splitArray(nums, numsSize, 2));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}