#include "wordBreak.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void test1()
{
    string s = "catsanddog";
    string word1 = "cat";
    string word2 = "cats";
    string word3 = "and";
    string word4 = "sand";
    string word5 = "dog";

    vector<string> wordDict = { word1, word2, word3, word4, word5 };

    Solution sln;
    auto result = sln.wordBreak(s, wordDict);

    cout << "test1(): " << endl;
    for (auto &str : result) {
        cout << str << endl;
    }
    cout << endl;
}

void test2()
{
    string s = "pineapplepenapple";
    string word1 = "apple";
    string word2 = "pen";
    string word3 = "applepen";
    string word4 = "pine";
    string word5 = "pineapple";

    vector<string> wordDict = {word1, word2, word3, word4, word5};

    Solution sln;
    auto result = sln.wordBreak(s, wordDict);

    cout << "test2(): " << endl;
    for (auto &str : result) {
        cout << str << endl;
    }
    cout << endl;
}

void test3()
{
    string s = "catsandog";

    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

    Solution sln;
    auto result = sln.wordBreak(s, wordDict);

    cout << "test3(): " << endl;
    for (auto &str : result) {
        cout << str << endl;
    }
    cout << endl;
}

void test4()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; 
    vector<string> wordDict = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    Solution sln;
    auto result = sln.wordBreak(s, wordDict);

    cout << "test4(): " << endl;
    for (auto &str : result) {
        cout << str << endl;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}