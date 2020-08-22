#ifndef __WORD_BREAK_H_
#define __WORD_BREAK_H_

#include <string>
#include <vector>
#include <memory>
using namespace std;

#define ALPHABETE_SIZE 26

struct Trie {
    Trie();
    ~Trie();

    Trie* child[ALPHABETE_SIZE];
    bool endFlag;
};

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict);

private:
    void backTrack(const string &word, int start, shared_ptr<Trie> trie, vector<vector<string>> &subset, vector<bool> &visited);
};

#endif