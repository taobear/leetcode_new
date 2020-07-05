#include "dailyTemperatures.h"

#include <stdio.h>
#include <stdlib.h>

void print_nums(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void test1()
{
    int T[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int TSize = sizeof(T) / sizeof(*T);

    int dtSize = 0;
    int *dt = dailyTemperatures(T, TSize, &dtSize);
    print_nums(dt, dtSize);
    free(dt);
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}