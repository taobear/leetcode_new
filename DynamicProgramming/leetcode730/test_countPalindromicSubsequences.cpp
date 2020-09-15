#include "countPalindromicSubsequences.h"

#include <stdio.h>

void test1()
{
    char S[] = "bccb";

    int ret = countPalindromicSubsequences(S);
    printf("test1(): %d\n", ret);
}

void test2()
{
    char S[] = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";

    int ret = countPalindromicSubsequences(S);
    printf("test2(): %d\n", ret);
}

void test3()
{
    char S[] = "bbbbb";

    int ret = countPalindromicSubsequences(S);
    printf("test3(): %d\n", ret);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}