#include "subsets.h"
#include "../func_2d_objs.h"

#include <stdio.h>
#include <stdlib.h>

void test1()
{
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(*nums);

    int *retSubsetColumn;
    int retSubsetNum;
    int **retSubset;
    retSubset = subsets(nums, numsSize, &retSubsetNum, &retSubsetColumn);
    
    printf("test1(): \n");
    print_2d_nums(retSubset, retSubsetNum, retSubsetColumn);

    free_2d_nums(retSubset, retSubsetNum, retSubsetColumn);
}

void test2()
{
    int nums[] = {1, 1, 2, 1, 4};
    int numsSize = sizeof(nums) / sizeof(*nums);

    int *retSubsetColumn;
    int retSubsetNum;
    int **retSubset;
    retSubset = subsets(nums, numsSize, &retSubsetNum, &retSubsetColumn);

    printf("test1(): \n");
    print_2d_nums(retSubset, retSubsetNum, retSubsetColumn);

    free_2d_nums(retSubset, retSubsetNum, retSubsetColumn);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}