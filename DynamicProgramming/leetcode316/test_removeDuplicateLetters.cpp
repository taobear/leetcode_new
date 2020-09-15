#include "removeDuplicateLetters.h"

#include <stdlib.h>
#include <stdio.h>

void test1()
{
    char s[] = "bcabc";

    char *letter = removeDuplicateLetters(s);

    printf("test1(): %s\n", letter);

    free(letter);
}

void test2()
{
    char s[] = "cbacdcbc";

    char *letter = removeDuplicateLetters(s);

    printf("test2(): %s\n", letter);

    free(letter);
}

void test3()
{
    char s[] = "bbcaac";

    char *letter = removeDuplicateLetters(s);

    printf("test3(): %s\n", letter);

    free(letter);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}