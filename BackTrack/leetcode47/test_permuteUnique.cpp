#include "permuteUnique.h"

#include "../func_2d_objs.h"

void test1()
{
    int nums[] = {1, 1, 2};
    int numsSize = sizeof(nums) / sizeof(*nums);

    int **retSet;
    int *retColunSize;
    int retSize;

    retSet = permuteUnique(nums, numsSize, &retSize, &retColunSize);

    print_2d_nums(retSet, retSize, retColunSize);
    free_2d_nums(retSet, retSize, retColunSize);
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}