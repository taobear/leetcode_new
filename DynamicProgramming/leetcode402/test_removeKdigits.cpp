#include "removeKdigits.h"

#include <stdlib.h>
#include <stdio.h>

void test1()
{
    char num[] = "1432219";
    int k = 3;

    char *res = removeKdigits(num, k);

    printf("test1(): %s\n", res);
    free(res);
}

void test2()
{
    char num[] = "10200";
    int k = 1;

    char *res = removeKdigits(num, k);

    printf("test2(): %s\n", res);
    free(res);
}

void test3()
{
    char num[] = "10";
    int k = 2;

    char *res = removeKdigits(num, k);

    printf("test3(): %s\n", res);
    free(res);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}