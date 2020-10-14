#include "lastStoneWeightII.h"

#include <stdio.h>

void test1()
{
    int stones[] = {2, 7, 4, 1, 8, 1};
    int stonesSize = sizeof(stones) / sizeof(*stones);

    printf("test1(): %d\n", lastStoneWeightII(stones, stonesSize));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}