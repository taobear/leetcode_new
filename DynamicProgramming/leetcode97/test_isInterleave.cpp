#include "isInterleave.h"

#include <stdio.h>

void test1()
{
    char s1[] = "aabcc";
    char s2[] = "dbbca";
    char s3[] = "aadbbcbcac";

    printf("test1(): %d\n", isInterleave(s1, s2, s3));
}

void test2()
{
    char s1[] = "aabcc";
    char s2[] = "dbbca";
    char s3[] = "aadbbbaccc";

    printf("test2(): %d\n", isInterleave(s1, s2, s3));
}

void test3()
{
    char s1[] = "";
    char s2[] = "";
    char s3[] = "";

    printf("test3(): %d\n", isInterleave(s1, s2, s3));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}