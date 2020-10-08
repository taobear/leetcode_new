#include "findTheLongestSubstring.h"

#include <stdio.h>

void test1()
{
    char s[] = "eleetminicoworoep";
    printf("test1(): %d\n", findTheLongestSubstring(s));
}

void test2()
{
    char s[] = "leetcodeisgreat";
    printf("test2(): %d\n", findTheLongestSubstring(s));
}

void test3()
{
    char s[] = "bcbcbc";
    printf("test3(): %d\n", findTheLongestSubstring(s));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}