#include "threeSum.h"

#include <stdio.h>
#include <stdlib.h>

void print_2d_nums(int **nums, int numsSize, int *numsColSize)
{
    if (nums == NULL || numsSize == 0 || numsColSize == NULL) {
        return;
    }

    printf("[\n");
    for (int i = 0; i < numsSize; ++i) {
        printf("  [");
        for (int j = 0; j < numsColSize[i] - 1; ++j) {
            printf("%d, ", nums[i][j]);
        }

        if (numsColSize[i] > 1) {
            printf("%d],\n", nums[i][numsColSize[i] - 1]);
        }
    }
    printf("]\n");
}

void test1()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize = 0;
    int *returnColumnSize = NULL;
    int **returnArray = NULL;

    returnArray = threeSum(nums, sizeof(nums) / sizeof(*nums), &returnSize, &returnColumnSize);

    print_2d_nums(returnArray, returnSize, returnColumnSize);

    for (int i = 0; i < returnSize; ++i) {
        free(returnArray[i]);
    }
    free(returnArray);
    free(returnColumnSize);
}

void test2()
{
    int nums[] = {0, 0, 0, 0, 0};
    int returnSize = 0;
    int *returnColumnSize = NULL;
    int **returnArray = NULL;

    returnArray = threeSum(nums, sizeof(nums) / sizeof(*nums), &returnSize, &returnColumnSize);

    print_2d_nums(returnArray, returnSize, returnColumnSize);

    for (int i = 0; i < returnSize; ++i) {
        free(returnArray[i]);
    }
    free(returnArray);
    free(returnColumnSize);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}