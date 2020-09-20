#include "cuttingRope.h"

#include <stdio.h>

void test1()
{
    int res = cuttingRope(2);

    printf("test1(): %d\n", res);
}

void test2()
{
    int res = cuttingRope(10);

    printf("test1(): %d\n", res);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}