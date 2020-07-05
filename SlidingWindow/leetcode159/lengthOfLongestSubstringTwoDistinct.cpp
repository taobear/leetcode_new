#include "lengthOfLongestSubstringTwoDistinct.h"

#include <limits.h>
#include <string.h>

int lengthOfLongestSubstringTwoDistinct(char *s)
{
    int len = 0, maxlen = 0;
    int slen = strlen(s);
    int difflen = 0;

    const int sizeOfAscii = CHAR_MAX;
    int countMap[sizeOfAscii];
    memset(countMap, 0, sizeOfAscii * sizeof(int));
    
    int head = 0;
    for (int tail = 0; tail < slen; ++tail) {
        char ch = s[tail];
        if (countMap[ch] == 0) {
            difflen ++;
        }

        countMap[ch]++;
        while (difflen > 2 && head < tail) {
            countMap[s[head]]--;
            if (countMap[s[head]] == 0) {
                difflen --;
            }
            head++;
        }

        if (difflen <= 2) {
            len = tail - head + 1;
            maxlen = len > maxlen ? len : maxlen;
        }
    }

    return maxlen;
}