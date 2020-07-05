#include "checkSubarraySum.h"

#include <iostream>
using namespace std;

void test1()
{
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;

    cout << "test1(): " << Solution().checkSubarraySum(nums, k) << endl;
}

void test2()
{
    vector<int> nums = {23, 2, 6, 4, 7};
    int k = 6;

    cout << "test2(): " << Solution().checkSubarraySum(nums, k) << endl;
}

void test3()
{
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = -6;

    cout << "test3(): " << Solution().checkSubarraySum(nums, k) << endl;
}

void test4()
{
    vector<int> nums = {23, 2, 6, 4, 7};
    int k = 0;

    cout << "test4(): " << Solution().checkSubarraySum(nums, k) << endl;
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    getchar();

    return 0;
}