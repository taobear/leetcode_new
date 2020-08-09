#include "wordBreak.h"

#include "wordBreak.h"
#include "../func_2d_objs.h"

#include <stdio.h>

void test1()
{
    char s[] = "catsanddog";
    char word1[] = "cat";
    char word2[] = "cats";
    char word3[] = "and";
    char word4[] = "sand";
    char word5[] = "dog";

    char *wordDict[] = { word1, word2, word3, word4, word5 };
    int wordDictSize = sizeof(wordDict) / sizeof(*wordDict);

    char **breakWords;
    int breakWordsSize = 0;
    breakWords = wordBreak(s, wordDict, wordDictSize, &breakWordsSize);

    print_2d_str(breakWords, breakWordsSize);
    free_2d_str(breakWords, breakWordsSize);
}

void test2()
{
    char s[] = "pineapplepenapple";
    char word1[] = "apple";
    char word2[] = "pen";
    char word3[] = "applepen";
    char word4[] = "pine";
    char word5[] = "pineapple";

    char *wordDict[] = {word1, word2, word3, word4, word5};
    int wordDictSize = sizeof(wordDict) / sizeof(*wordDict);

    char **breakWords;
    int breakWordsSize = 0;
    breakWords = wordBreak(s, wordDict, wordDictSize, &breakWordsSize);

    print_2d_str(breakWords, breakWordsSize);
    free_2d_str(breakWords, breakWordsSize);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}