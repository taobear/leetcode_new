#include "minCostII.h"

#include <stdio.h>

void test1()
{
    int cost1[] = {1, 5, 3};
    int cost2[] = {2, 9, 4};

    int *costs[] = {cost1, cost2};
    int costsSize = sizeof(costs) / sizeof(*costs);

    int costsColSize[] = {3, 3};

    printf("test1(): %d\n", minCostII(costs, costsSize, costsColSize));
}

void test2()
{
    int cost1[] = { 15, 17, 15, 20, 7, 16, 6, 10, 4, 20, 7,  3, 4 };
    int cost2[] = { 11,  3,  9, 13, 7, 12, 6,  7, 5,  1, 7, 18, 9 };

    int* costs[] = { cost1, cost2 };
    int costsSize = sizeof(costs) / sizeof(*costs);

    int costsColSize[] = { 13, 13 };

    printf("test2(): %d\n", minCostII(costs, costsSize, costsColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}