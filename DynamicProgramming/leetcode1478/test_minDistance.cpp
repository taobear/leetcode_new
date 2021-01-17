#include "minDistance.h"

#include <stdio.h>

void test1()
{
    int houses[] = {1, 4, 8, 10, 20};
    int housesSize = sizeof(houses) / sizeof(*houses);

    int k = 3;

    printf("test1(): %d\n", minDistance(houses, housesSize, k));
}

void test2()
{
    int houses[] = { 2, 3, 5, 12, 18 };
    int housesSize = sizeof(houses) / sizeof(*houses);

    int k = 2;

    printf("test2(): %d\n", minDistance(houses, housesSize, k));
}

void test3()
{
    int houses[] = { 7, 4, 6, 11 };
    int housesSize = sizeof(houses) / sizeof(*houses);

    int k = 1;

    printf("test3(): %d\n", minDistance(houses, housesSize, k));
}

void test4()
{
    int houses[] = { 3, 6, 14, 10 };
    int housesSize = sizeof(houses) / sizeof(*houses);

    int k = 4;

    printf("test4(): %d\n", minDistance(houses, housesSize, k));
}

void test5()
{
    int houses[] = {48, 43, 20, 18, 6, 5, 35, 41, 1, 2, 27, 17, 37};
    int housesSize = sizeof(houses) / sizeof(*houses);

    int k = 7;

    printf("test5(): %d\n", minDistance(houses, housesSize, k));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    test5();

    return 0;
}