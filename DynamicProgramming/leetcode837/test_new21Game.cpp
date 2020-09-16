#include "new21Game.h"

#include <stdio.h>

void test1()
{
    int N = 10, K = 1, W = 10;
    printf("test1(): %f\n", new21Game(N, K, W));
}

void test2()
{
    int N = 10, K = 2, W = 10;
    printf("test2(): %f\n", new21Game(N, K, W));
}

void test3()
{
    int N = 6, K = 1, W = 10;
    printf("test3(): %f\n", new21Game(N, K, W));
}

void test4()
{
    int N = 21, K = 17, W = 10;
    printf("test4(): %f\n", new21Game(N, K, W));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}