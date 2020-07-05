#include "largestRectangleArea.h"

#include <stdio.h>

void test1()
{
    int heights[] = {2, 1, 5, 6, 2, 3};
    int heightsSize = sizeof(heights) / sizeof(*heights);

    printf("test1(): %d\n", largestRectangleArea(heights, heightsSize));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}