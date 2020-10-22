#include "findMinMoves.h"

#include <stdio.h>

void test1()
{
    int machines[] = {1, 0, 5};
    int machinesSize = sizeof(machines) / sizeof(*machines);

    printf("test1(): %d\n", findMinMoves(machines, machinesSize));
}

void test2()
{
    int machines[] = {0, 3, 0};
    int machinesSize = sizeof(machines) / sizeof(*machines);

    printf("test2(): %d\n", findMinMoves(machines, machinesSize));
}

void test3()
{
    int machines[] = {0, 2, 0};
    int machinesSize = sizeof(machines) / sizeof(*machines);

    printf("test3(): %d\n", findMinMoves(machines, machinesSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}