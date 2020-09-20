#include "leastOpsExpressTarget.h"

#include <stdio.h>

void test1()
{
    int x = 3, target = 19;

    printf("test1(): %d\n", leastOpsExpressTarget(x, target));
}

void test2()
{
    int x = 5, target = 501;

    printf("test2(): %d\n", leastOpsExpressTarget(x, target));
}

void test3()
{
    int x = 100, target = 100000000;

    printf("test3(): %d\n", leastOpsExpressTarget(x, target));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}