#include "distinctSubseqII.h"

#include <stdio.h>

void test1()
{
    char S[] = "abc";

    printf("test1(): %d\n", distinctSubseqII(S));
}

void test2()
{
    char S[] = "aba";

    printf("test2(): %d\n", distinctSubseqII(S));
}

void test3()
{
    char S[] = "aaa";

    printf("test3(): %d\n", distinctSubseqII(S));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}