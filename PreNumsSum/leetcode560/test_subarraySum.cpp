#include "subarraySum.h"

#include <iostream>

#include <stdio.h>

void test1()
{
    std::vector<int> nums = {1, 1, 1};
    int k = 2;

    std::cout << "test1(): " << Solution().subarraySum(nums, k) << std::endl;
}

void test2()
{
    std::vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int k = 0;

    std::cout << "test2(): " << Solution().subarraySum(nums, k) << std::endl;
}

int main(int argc, char **argv)
{
    test1();

    test2();

    getchar();

    return 0;
}