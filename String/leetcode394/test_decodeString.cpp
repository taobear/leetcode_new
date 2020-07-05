#include "decodeString.h"

#include <stdio.h>
#include <stdlib.h>

void test1()
{
    char s[] = "3[a]2[bc]";
    char *ret = decodeString(s);

    printf("test1(): %s", ret);
    free(ret);
}

void test2()
{
    char s[] = "3[a2[c]]";
    char *ret = decodeString(s);

    printf("test2(): %s", ret);
    free(ret);
}

void test3()
{
    char s[] = "2[abc]3[cd]ef";
    char *ret = decodeString(s);

    printf("test3(): %s", ret);
    free(ret);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}