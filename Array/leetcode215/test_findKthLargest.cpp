#include "findKthLargest.h"

#include <stdio.h>

void test1()
{
    int nums[] = {3, 2, 1, 5, 6, 4};
    int k = 2;

    printf("test1(): %d\n", findKthLargest(nums, numsSize, k));
}

void test2()
{
    int nums[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    printf("test2(): %d\n", findKthLargest(nums, numsSize, k));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}