#include "canCross.h"

#include <stdio.h>

void test1()
{
    int stones[] = {0, 1, 3, 5, 6, 8, 12, 17};
    int stonesSize = sizeof(stones) / sizeof(*stones);

    printf("test1(): %d\n", canCross(stones, stonesSize));
}

void test2()
{
    int stones[] = {0, 1, 2, 3, 4, 8, 9, 11};
    int stonesSize = sizeof(stones) / sizeof(*stones);

    printf("test2(): %d\n", canCross(stones, stonesSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}