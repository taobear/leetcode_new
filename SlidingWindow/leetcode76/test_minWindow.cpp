#include "minWindow.h"

#include <stdio.h>

void test1()
{
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";

    printf("test1() result: %s\n", minWindow(s, t));
}

void test2()
{
    char s[] = "cabwefgewcwaefgcf";
    char t[] = "cae";

    printf("test2() result: %s\n", minWindow(s, t));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    getchar();

    return 0;
}