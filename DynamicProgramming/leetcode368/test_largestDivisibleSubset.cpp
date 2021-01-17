#include "largestDivisibleSubset.h"

#include <stdio.h>

void test1()
{
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(*nums);

    int *ret, retSize;
    ret = largestDivisibleSubset(nums, numsSize, &retSize);


}

void test2()
{
    int nums[] = {1, 2, 4, 8};
    int numsSize = sizeof(nums) / sizeof(*nums);

    int *ret, retSize;
    ret = largestDivisibleSubset(nums, numsSize, &retSize);


}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}