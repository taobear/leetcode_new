#include "superEggDrop.h"

#include <stdio.h>

void test1()
{
    int K = 1, N = 2;
    printf("test1(): %d\n", superEggDrop(K, N));
}

void test2()
{
    int K = 2, N = 6;
    printf("test2(): %d\n", superEggDrop(K, N));
}

void test3()
{
    int K = 3, N = 14;
    printf("test3(): %d\n", superEggDrop(K, N));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}