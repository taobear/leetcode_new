#include "minCost.h"

#include <stdio.h>

void test1()
{
    int n = 7;
    int cuts[] = {1, 3, 4, 5};
    int cutsSize = sizeof(cuts) / sizeof(*cuts);

    printf("test1(): %d\n", minCost(n, cuts, cutsSize));
}

void test2()
{
    int n = 9;
    int cuts[] = {5, 6, 1, 4, 2};
    int cutsSize = sizeof(cuts) / sizeof(*cuts);

    printf("test2(): %d\n", minCost(n, cuts, cutsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}