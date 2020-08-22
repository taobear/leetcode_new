#include "combinationSum.h"

#include "../func_2d_objs.h"

void test1()
{
    int candidates[] = {2, 3, 6, 7};
    int candidatesSize = sizeof(candidates) / sizeof(*candidates);
    int target = 7;

    int combNum = 0;
    int *combSize = 0;
    int **comb;

    comb = combinationSum(candidates, candidatesSize, target, &combNum, &combSize);

    print_2d_nums(comb, combNum, combSize);
    free_2d_nums(comb, combNum, combSize);
}

void test2()
{
    int candidates[] = {2, 3, 5};
    int candidatesSize = sizeof(candidates) / sizeof(*candidates);
    int target = 8;

    int combNum = 0;
    int *combSize = 0;
    int **comb;

    comb = combinationSum(candidates, candidatesSize, target, &combNum, &combSize);

    print_2d_nums(comb, combNum, combSize);
    free_2d_nums(comb, combNum, combSize);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}