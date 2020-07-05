#include "maxProduct.h"

#include <stdlib.h>
#include <stdio.h>

void test1()
{
    int nums[] = {2, 3, -2, 4};
    int numsSize = 4;

    printf("test1(): %d\n", maxProduct(nums, numsSize));
}

void test2()
{
    int nums[] = {-2, 0, -1};
    int numsSize = 3;

    printf("test2(): %d\n", maxProduct(nums, numsSize));
}

void test3()
{
    int nums[] = {-4, -3, -2};
    int numsSize = sizeof(nums) / sizeof(*nums);

    printf("test3(): %d\n", maxProduct(nums, numsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();
    
    test3();

    return 0;
}