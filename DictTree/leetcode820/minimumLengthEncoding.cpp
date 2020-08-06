#include "minimumLengthEncoding.h"

#include <stdlib.h>

#define CHAR_MAX_SIZE 26

typedef struct Trie
{
    struct Trie *next[CHAR_MAX_SIZE];
    int deepth;
    bool endFlag;
} Trie;

void initTrieNode(Trie *node)
{
    if (node == NULL)
    {
        return;
    }

    for (int index = 0; index < CHAR_MAX_SIZE; ++index)
    {
        node->next[index] = NULL;
    }

    node->endFlag = false;
}

Trie *trieCreate()
{
    Trie *root = (Trie *)malloc(sizeof(Trie));
    if (root == NULL)
    {
        return root;
    }

    initTrieNode(root);

    root->deepth = 1;
    return root;
}

int trieInsertReverseAppendLength(Trie *trie, char *word)
{
    if (trie == NULL || word == NULL)
    {
        return 0;
    }

    int len = strlen(word);
    int minDeepth = 0;
    bool newNodeFlag = false;
    Trie *node = trie;
    for (int i = 0; i < len; ++i)
    {
        int index = word[len - i - 1] - 'a';
        if (node->next[index] == NULL)
        {
            Trie *newNode = (Trie *)(malloc(sizeof(Trie)));
            if (newNode == NULL)
            {
                return minDeepth;
            }

            initTrieNode(newNode);
            newNode->deepth = node->deepth + 1;

            node->next[index] = newNode;
            newNodeFlag = true;
        }

        if (node->endFlag == true)
        {
            minDeepth = node->deepth;
            node->endFlag = false;
        }

        node = node->next[index];
    }

    if (newNodeFlag != true)
    {
        return 0;
    }

    node->endFlag = true;
    return node->deepth - minDeepth;
}

int minimumLengthEncoding(char **words, int wordsSize)
{
    if (words == NULL || wordsSize == 0)
    {
        return 0;
    }

    int result = 0;
    Trie *trie = trieCreate();
    for (int wi = 0; wi < wordsSize; ++wi)
    {
        result += trieInsertReverseAppendLength(trie, words[wi]);
    }

    return result;
}