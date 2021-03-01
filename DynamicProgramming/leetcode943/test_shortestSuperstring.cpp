#include "shortestSuperstring.h"

#include <stdio.h>

void test1()
{
    char word1[] = "alex";
    char word2[] = "loves";
    char word3[] = "leetcode";

    char *words[] = {word1, word2, word3};
    int wordsSize = sizeof(words) / sizeof(*words);

    printf("test1(): %s\n", shortestSuperstring(words, wordsSize));
}

void test2()
{
    char word1[] = "catg";
    char word2[] = "ctaagt";
    char word3[] = "gcta";
    char word4[] = "ttca";
    char word5[] = "atgcatc";

    char *words[] = {word1, word2, word3, word4, word5};
    int wordsSize = sizeof(words) / sizeof(*words);

    printf("test1(): %s\n", shortestSuperstring(words, wordsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}