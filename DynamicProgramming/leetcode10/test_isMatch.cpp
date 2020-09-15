#include "isMatch.h"

#include <stdio.h>

void test1()
{
    char s[] = "aaa";
    char p[] = "a";

    bool flag = isMatch(s, p);
    printf("test1(): %d\n", flag);
}

void test2()
{
    char s[] = "aab";
    char p[] = "c*a*b";

    bool flag = isMatch(s, p);
    printf("test2(): %d\n", flag);
}

void test3()
{
    char s[] = "aaa";
    char p[] = "a*";

    bool flag = isMatch(s, p);
    printf("test3(): %d\n", flag);
}

void test4()
{
    char s[] = "aaa";
    char p[] = "a.*";

    bool flag = isMatch(s, p);
    printf("test4(): %d\n", flag);
}

void test5()
{
    char s[] = "aaa";
    char p[] = "a.a";

    bool flag = isMatch(s, p);
    printf("test5(): %d\n", flag);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    test5();

    return 0;
}