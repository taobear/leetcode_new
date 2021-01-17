#include "minCost.h"

#include <stdio.h>

void test1()
{
    int cost1[] = {17, 2, 17};
    int cost2[] = {16, 16, 5};
    int cost3[] = {14, 3, 19};

    int *costs[] = {cost1, cost2, cost3};
    int costsSize = sizeof(costs) / sizeof(*costs);

    int costsColSize[] = {3, 3, 3};

    printf("test1(): %d\n", minCost(costs, costsSize, costsColSize));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}