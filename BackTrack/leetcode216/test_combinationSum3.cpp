#include "combinationSum3.h"

#include "../func_2d_objs.h"

void test1()
{
    int k = 3, n = 7;

    int **comb;
    int returnSize = 0;
    int *returnColumnSize;

    comb = combinationSum3(k, n, &returnSize, &returnColumnSize);

    print_2d_nums(comb, returnSize, returnColumnSize);
    free_2d_nums(comb, returnSize, returnColumnSize);
}

void test2()
{
    int k = 3, n = 9;

    int **comb;
    int returnSize = 0;
    int *returnColumnSize;

    comb = combinationSum3(k, n, &returnSize, &returnColumnSize);

    print_2d_nums(comb, returnSize, returnColumnSize);
    free_2d_nums(comb, returnSize, returnColumnSize);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}