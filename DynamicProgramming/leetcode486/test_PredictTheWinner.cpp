#include "PredictTheWinner.h"

#include <stdio.h>

void test1()
{
    int nums[] = {1, 5, 2};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test1(): %d\n", PredictTheWinner(nums, numsSize));
}

void test2()
{
    int nums[] = {1, 5, 233, 7};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test2(): %d\n", PredictTheWinner(nums, numsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}