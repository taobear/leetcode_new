#include "longestValidParentheses.h"

#include <stdio.h>

void test1()
{
    char s[] = "(()";
    printf("test1(): %d\n", longestValidParentheses(s));
}

void test2()
{
    char s[] = ")()())";
    printf("test2(): %d\n", longestValidParentheses(s));
}

void test3()
{
    char s[] = "";
    printf("test3(): %d\n", longestValidParentheses(s));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}