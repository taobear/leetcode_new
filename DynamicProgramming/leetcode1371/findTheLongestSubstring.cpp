#include "findTheLongestSubstring.h"

#include <stdlib.h>
#include <string.h>

#define VOWEL_NUM 5

int findTheLongestSubstring(char* s)
{
    int slen = strlen(s);
    if (slen == 0) {
        return 0;
    }

    const char vowel[VOWEL_NUM] = {'a', 'e', 'i', 'o', 'u'};

    int first[VOWEL_NUM];
    for (int i = 0; i < VOWEL_NUM; i++) {
        first[i] = -1;
    }

    int result = 0;
    int curLen[VOWEL_NUM] = {0};
    int evenFlag[VOWEL_NUM] = {0};
    for (int i = 0; i < slen; i++) {
        int minLen = INT_MAX;
        for (int j = 0; j < VOWEL_NUM; j++) {
            if (vowel[j] != s[i]) {
                curLen[j] += 1;
            } else {
                if (first[j] == -1) {
                    first[j] = i;
                    curLen[j] = 0;
                } else {
                    evenFlag[j] = ~evenFlag[j];
                    curLen[j] = evenFlag[j] ? i + 1 : i - first[j];
                }
            }

            minLen = curLen[j] > minLen ? minLen : curLen[j];
        }

        result = result > minLen ? result : minLen;
    }

    return result;
}