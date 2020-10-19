#include "getLengthOfOptimalCompression.h"

#include <stdio.h>

void test1()
{
    char s[] = "aaabcccd";
    int k = 2;

    printf("test1(): %d\n", getLengthOfOptimalCompression(s, k));
}

void test2()
{
    char s[] = "aabbaa";
    int k = 2;

    printf("test2(): %d\n", getLengthOfOptimalCompression(s, k));
}

void test3()
{
    char s[] = "aaaaaaaaaaa";
    int k =0;

    printf("test3(): %d\n", getLengthOfOptimalCompression(s, k));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}