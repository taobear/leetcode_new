#include "findSubstringInWraproundString.h"

#include <stdio.h>

void test1()
{
    char s[] = "a";
    int ret = findSubstringInWraproundString(s);

    printf("test1(): %d\n", ret);
}

void test2()
{
    char s[] = "cac";
    int ret = findSubstringInWraproundString(s);

    printf("test2(): %d\n", ret);
}

void test3()
{
    char s[] = "zab";
    int ret = findSubstringInWraproundString(s);

    printf("test3(): %d\n", ret);
}

void test4()
{
    char s[] = "zaba";
    int ret = findSubstringInWraproundString(s);

    printf("test4(): %d\n", ret);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}