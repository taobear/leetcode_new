#include "shortestSuperstring.h"

#include <string.h>
#include <stdlib.h>

#define WORD_SIZE 12
#define WORD_LEN 20

int maxOverlapLength(char** words, int x, int y)
{
    if (x == y) {
        return strlen(words[x]);
    }

    int m = strlen(words[x]);
    int n = strlen(words[y]);
    int maxlen = m > n ? n : m;
    for (int l = maxlen; l > 0; l--) {
        if (strncmp(words[x] + m - l, words[y], l) == 0) {
            return l;
        }
    }

    return 0;
}

int g_overlapMapLength[WORD_SIZE][WORD_SIZE];

void buildOverlapMap(char** words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            g_overlapMapLength[i][j] = maxOverlapLength(words, i, j);
        }
    }
}

void rebuildSsOrder(char** words, int wordsSize, int* bestOrder)
{
    int maxState = 1 << wordsSize;
    int overlapLen[maxState][wordsSize];
    memset(overlapLen, 0, sizeof(int) * maxState * wordsSize);

    int prev[maxState][wordsSize];
    for (int state = 0; state < maxState; state++) {
        for (int last = 0; last < wordsSize; last++) {
            if ((state & (1 << last)) == 0) {
                continue;
            }

            int prevState = state ^ (1 << last);
            for (int curr = 0; curr < wordsSize; curr++) {
                if ((state & (1 << curr)) == 0) {
                    continue;
                }

                int newOvlLen = overlapLen[prevState][curr] + g_overlapMapLength[curr][last];
                if (overlapLen[state][last] > newOvlLen) {
                    continue;
                }

                prev[state][last] = curr;
                overlapLen[state][last] = curr;
            }
        }
    }

    int maxLast = 0;
    int maxOverlap = 0;
    for (int last = 0; last < wordsSize; last++) {
        if (maxOverlap > overlapLen[maxState - 1][last]) {
            continue;
        }

        maxLast = last;
        maxOverlap = overlapLen[maxState - 1][last];
    }

    int currLast = maxLast;
    int currState = maxState - 1;
    for (int index = wordsSize - 1; index >= 0; index--) {
        bestOrder[index] = currLast;
        currLast = prev[currState][currLast];
        currState = currState ^ (1 << currLast);
    }
}

char* shortestSuperstring(char** words, int wordsSize)
{
    buildOverlapMap(words, wordsSize);

    int bestOrder[wordsSize];
    rebuildSsOrder(words, wordsSize, bestOrder);

    char* ret = (char*)malloc(WORD_SIZE * WORD_LEN + 1);
    int retLen = 0;

    int prev = bestOrder[0];
    int prevLen = strlen(words[prev]);

    memcpy(ret, words[prev], strlen(words[prev]));
    retLen = prevLen;

    for (int index = 1; index < wordsSize; index++) {
        int curr = bestOrder[index];
        int currLen = strlen(words[curr]);
        int ovlLen = g_overlapMapLength[prev][curr];
        memcpy(ret + retLen, words[prev] + ovlLen, currLen - ovlLen);
        retLen = retLen + currLen - ovlLen;
    }

    ret[retLen] = '\0';
    return ret;
}