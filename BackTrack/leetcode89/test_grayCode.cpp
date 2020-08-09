#include "grayCode.h"

#include <stdio.h>
#include <stdlib.h>

void print_1d_nums(int *nums, int numsSize)
{
    printf("[");
    for (int i = 0; i < numsSize - 1; ++i) {
        printf("%d, ", nums[i]);
    }

    printf("%d]\n", nums[numsSize - 1]);
}

void test1()
{
    int retGraySize = 0;
    int *retGray = grayCode(0, &retGraySize);

    print_1d_nums(retGray, retGraySize);
    free(retGray);
}

void test2()
{
    int retGraySize = 0;
    int *retGray = grayCode(3, &retGraySize);

    print_1d_nums(retGray, retGraySize);
    free(retGray);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}