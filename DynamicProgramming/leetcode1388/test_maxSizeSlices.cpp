#include "maxSizeSlices.h"

#include <stdio.h>

void test1()
{
    int slices[] = {1, 2, 3, 4, 5, 6};
    int slicesSize = sizeof(slices) / sizeof(*slices);

    printf("test1(): %d\n", maxSizeSlices(slices, slicesSize));
}

void test2()
{
    int slices[] = {8, 9, 8, 6, 1, 1};
    int slicesSize = sizeof(slices) / sizeof(*slices);

    printf("test2(): %d\n", maxSizeSlices(slices, slicesSize));
}

void test3()
{
    int slices[] = {4, 1, 2, 5, 8, 3, 1, 9, 7};
    int slicesSize = sizeof(slices) / sizeof(*slicesSize);

    printf("test3(): %d\n", maxSizeSlices(slices, slicesSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}