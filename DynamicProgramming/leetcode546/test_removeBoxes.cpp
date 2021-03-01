#include "removeBoxes.h"

#include <stdio.h>

void test1()
{
    int boxes[] = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    int boxesSize = sizeof(boxes) / sizeof(*boxes);

    printf("test1(): %d\n", removeBoxes(boxes, boxesSize));
}

void test2()
{
    int boxes[] = {1, 1, 1};
    int boxesSize = sizeof(boxes) / sizeof(*boxes);

    printf("test2(): %d\n", removeBoxes(boxes, boxesSize));
}

void test3()
{
    int boxes[] = {1};
    int boxesSize = sizeof(boxes) / sizeof(*boxes);

    printf("test3(): %d\n", removeBoxes(boxes, boxesSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}