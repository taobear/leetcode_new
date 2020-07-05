#include "minKnightMoves.h"

#include <stdio.h>

void test1()
{
    printf("test1(): %d\n", minKnightMoves(2, 1));
}

void test2()
{
    printf("test2(): %d\n", minKnightMoves(5, 5));
}

void test3()
{
    printf("test3(): %d\n", minKnightMoves(0, 1));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    getchar();
 
    return 0;
}