#include "tilingRectangle.h"

#include <stdio.h>

void test1()
{
    int n = 2, m = 3;
    printf("test1(): %d\n", tilingRectangle(n, m));
}

void test2()
{
    int n = 5, m = 8;
    printf("test2(): %d\n", tilingRectangle(n, m));
}

void test3()
{
    int n = 11, m = 13;
    printf("test3(): %d\n", tilingRectangle(n, m));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}