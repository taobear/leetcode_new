#include "nextGreaterElements.h"

#include <stdio.h>
#include <stdlib.h>

void print_elements(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }

    printf("\n");
}

void test1()
{
    int nums[] = {1, 2, 1};
    int numsSize = 3;
    int returnSize = 0;

    int *elements = nextGreaterElements(nums, numsSize, &returnSize);
    print_elements(elements, returnSize);
    free(elements);
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}