#include "wordBreak.h"

#include <memory>
#include <vector>
#include <string>

using namespace std;

void trieInit(Trie *trie)
{
    for (int index = 0; index < ALPHABETE_SIZE; ++index) {
        trie->child[index] = nullptr;
    }

    trie->endFlag = false;
}

void trieFree(Trie *trie)
{
    if (trie == NULL) {
        return;
    }

    for (int index = 0; index < ALPHABETE_SIZE; ++index) {
        trieFree(trie->child[index]);
    }

    free(trie);
}

void trieInsert(shared_ptr<Trie> trie, const string &word)
{
    Trie *trieIter = trie.get();
    int len = word.size();
    for (int index = 0; index < len; ++index) {
        int matchIndex = word[index] - 'a';
        if (trieIter->child[matchIndex] == nullptr) {
            trieIter->child[matchIndex] = (Trie *)malloc(sizeof(Trie));
            trieInit(trieIter->child[matchIndex]);
        }
        trieIter = trieIter->child[matchIndex];
    }
    trieIter->endFlag = true;
}

Trie::Trie()
{
    trieInit(this);
}

Trie::~Trie()
{
    for (int index = 0; index < ALPHABETE_SIZE; ++index) {
        trieFree(this->child[index]);
    }
}

vector<string> Solution::wordBreak(string s, vector<string> &wordDict)
{
    int len = s.size();
    vector<vector<string>> subset(len);
    shared_ptr<Trie> trie = make_shared<Trie>();
    for (auto &word : wordDict) {
        trieInsert(trie, word);
    }

    vector<bool> visited(len, false);
    backTrack(s, 0, trie, subset, visited);
    return subset[0];
}

void Solution::backTrack(const string &word, int start, shared_ptr<Trie> trie, vector<vector<string>> &subset, vector<bool> &visited)
{
    int len = word.size();
    Trie* trieIter = trie.get();
    for (int index = start; index < len; ++index) {
        int ch = word[index] - 'a';
        if (trieIter->child[ch] == nullptr) {
            break;
        }

        if (trieIter->child[ch]->endFlag == true) {
            if (index == len - 1) {
                subset[start].push_back(word.substr(start, len - start));
                continue;
            }

            if (visited[index + 1] == false) {
                backTrack(word, index + 1, trie, subset, visited);
            }

            for (auto &str : subset[index + 1]) {
                subset[start].push_back(word.substr(start, index - start + 1) + " " + str);
            }
        }

        trieIter = trieIter->child[ch];
    }

    visited[start] = true;
}