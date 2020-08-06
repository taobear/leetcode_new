#include "maximizeSweetness.h"

#include <stdio.h>

void test1()
{
    int sweetness = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int K = 5;

    printf("test1(): %d\n", maximizeSweetness(sweetness, sizeof(sweetness) / sizeof(*sweetness), K));
}

void test2()
{
    int sweetness = {5, 6, 7, 8, 9, 1, 2, 3, 4};
    int K = 8;

    printf("test2(): %d\n", maximizeSweetness(sweetness, sizeof(sweetness) / sizeof(*sweetness), K));
}

void test3()
{
    int sweetness = {1, 2, 2, 1, 2, 2, 1, 2, 2};
    int K = 2;

    printf("test3(): %d\n", maximizeSweetness(sweetness, sizeof(sweetness) / sizof(*sweetness), K));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}