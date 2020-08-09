#include "wordBreak.h"

#include <stdlib.h>
#include <string.h>

#define ALPHABETE_SIZE 26
#define BREAKWORD_SIZE 100000
typedef struct Trie {
    struct Trie *child[ALPHABETE_SIZE];
    bool endFlag;
} Trie;

void trieInit(Trie *trie)
{
    for (int index = 0; index < ALPHABETE_SIZE; ++index) {
        trie->child[index] = NULL;
    }
    trie->endFlag = false;
}

Trie *trieCreate()
{
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    if (trie == NULL) {
        return NULL;
    }

    trieInit(trie);
    return trie;
}

void trieInsert(Trie *trie, char *word)
{
    int len = strlen(word);
    for (int i = 0; i < len; ++i) {
        int matchIndex = word[i] - 'a';
        if (trie->child[matchIndex] == NULL) {
            trie->child[matchIndex] = (Trie *)malloc(sizeof(Trie));
            trieInit(trie->child[matchIndex]);
        }

        trie = trie->child[matchIndex];
    }
    trie->endFlag = true;
}

void trieFree(Trie *trie)
{
    if (trie == NULL) {
        return;
    }

    for (int i = 0; i < ALPHABETE_SIZE; ++i) {
        trieFree(trie->child[i]);
    }
    free(trie);
}

void backTrack(char *s, Trie *trie, char **breakWords, int *breakWordsSize, char *tmpBreakWord, int currLen)
{
    if (*s == '\0') {
        breakWords[*breakWordsSize] = (char *)malloc(sizeof(char) * (currLen + 1));
        memcpy(breakWords[*breakWordsSize], tmpBreakWord, currLen);
        breakWords[*breakWordsSize][currLen] = '\0';
        *breakWordsSize = *breakWordsSize + 1;
        return;
    }

    int slen = strlen(s);
    Trie *trieIter = trie;
    for (int index = 0; index < slen; ++index) {
        int chId = s[index] - 'a';
        if (trieIter->child[chId] == NULL) {
            break;
        }

        if (trieIter->child[chId]->endFlag == true) {
            int spaceLen = 0;
            if (currLen != 0) {
                tmpBreakWord[currLen] = ' ';
                spaceLen = 1;
            }
            memcpy(tmpBreakWord + currLen + spaceLen, s, index + 1);
            backTrack(s + index + 1, trie, breakWords, breakWordsSize, tmpBreakWord, currLen + index + 1 + spaceLen);
        }
        trieIter = trieIter->child[chId];
    }
}

char **wordBreak(char *s, char **wordDict, int wordDictSize, int *returnSize)
{
    Trie *trie = trieCreate();
    for (int i = 0; i < wordDictSize; ++i) {
        trieInsert(trie, wordDict[i]);
    }

    char **breakWords = (char **)malloc(BREAKWORD_SIZE * sizeof(char *));
    int breakWordSize = 0;

    int slen = strlen(s);
    char tmpBreakWord[slen * 2 + 1];
    backTrack(s, trie, breakWords, &breakWordSize, tmpBreakWord, 0);

    trieFree(trie);
    *returnSize = breakWordSize;
    return breakWords;
}