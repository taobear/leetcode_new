#include "lengthOfLongestSubstringTwoDistinct.h"

#include <stdio.h>

void test1()
{
    char s[] = "eceba";
    printf("test1(): %d\n", lengthOfLongestSubstringTwoDistinct(s));
}

void test2()
{
    char s[] = "ccaabbb";
    printf("test2(): %d\n", lengthOfLongestSubstringTwoDistinct(s));
}

void test3()
{
    char s[] = "a";
    printf("test3(): %d\n", lengthOfLongestSubstringTwoDistinct(s));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    getchar();

    return 0;
}