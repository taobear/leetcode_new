#include "trap.h"

#include <stdlib.h>
#include <stdio.h>

void test1()
{
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int heightSize = sizeof(height) / sizeof(*height);

    printf("test1(): %d\n", trap(height, heightSize));
}

void test2()
{
    int height[] = {};
    int heightSize = 0;

    printf("test2(): %d\n", trap(height, heightSize));
}

void test3()
{
    int height[] = {0};
    int heightSize = 1;

    printf("test3(): %d\n", trap(height, heightSize));
}

void test4()
{
    int height[] = {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
    int heightSize = sizeof(height) /sizeof(*height);

    printf("test4(): %d\n", trap(height, heightSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}