#include "shortestWay.h"

#include <stdio.h>

void test0()
{
    int index[] = {1, 3, 5, 7};

    printf("test0() 1: %d\n", findUpperIndex(index, sizeof(index) / sizeof(*index), 0));
    printf("test0() 2: %d\n", findUpperIndex(index, sizeof(index) / sizeof(*index), 2));
    printf("test0() 3: %d\n", findUpperIndex(index, sizeof(index) / sizeof(*index), 4));
    printf("test0() 4: %d\n", findUpperIndex(index, sizeof(index) / sizeof(*index), 6));
    printf("test0() 5: %d\n", findUpperIndex(index, sizeof(index) / sizeof(*index), 8));
}

void test1()
{
    char source[] = "abc";
    char target[] = "abcbc";

    printf("test1(): %d\n", shortestWay(source, target));
}

void test2()
{
    char source[] = "abc";
    char target[] = "acdbc";

    printf("test2(): %d\n", shortestWay(source, target));
}

void test3()
{
    char source[] = "xyz";
    char target[] = "xzyxz";

    printf("test3(): %d\n", shortestWay(source, target));
}

void test4()
{
    char source[] = "aaaaa";
    char target[] = "aaaaaaaaaaaaa";

    printf("test4(): %d\n", shortestWay(source, target));
}

int main(int argc, char **argv)
{
    test0();

    test1();

    test2();

    test3();

    test4();

    getchar();

    return 0;
}