#include "numOfWays.h"

#include <stdio.h>

void test1()
{
    int nums[] = {2, 1, 3};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test1(): %d\n", numOfWays(nums, numsSize));
}

void test2()
{
    int nums[] = {3, 4, 5, 1, 2};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test2(): %d\n", numOfWays(nums, numsSize));
}

void test3()
{
    int nums[] = { 1, 2, 3 };
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test3(): %d\n", numOfWays(nums, numsSize));
}

void test4()
{
    int nums[] = { 3, 1, 2, 5, 4, 6 };
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test4(): %d\n", numOfWays(nums, numsSize));
}

void test5()
{
    int nums[] = { 9, 4, 2, 1, 3, 6, 5, 7, 8, 14, 11, 10, 12, 13, 16, 15, 17, 18 };
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test5(): %d\n", numOfWays(nums, numsSize));
}

void test6()
{
    int nums[] = { 6, 9, 11, 15, 1, 12, 3, 2, 7, 8, 14, 4, 5, 13, 10 };
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test6(): %d\n", numOfWays(nums, numsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    test5();

    test6();

    return 0;
}