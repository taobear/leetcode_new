#include "lengthOfLongestSubstring.h"

#include <string.h>
#include <limits.h>

int lengthOfLongestSubstring(char *s)
{
    int len = 0, maxlen = 0;
    int slen = strlen(s);

    const int sizeAscii = CHAR_MAX + 1;
    int indexMap[sizeAscii];
    for (int i = 0; i < sizeAscii; ++i)
    {
        indexMap[i] = -1;
    }

    int head = 0;
    for (int tail = 0; tail < slen; ++tail)
    {
        char c = s[tail];
        if (indexMap[c] != -1)
        {
            head = (indexMap[c] + 1) > head ? (indexMap[c] + 1) : head;
        }

        len = tail - head + 1;
        maxlen = len > maxlen ? len : maxlen;
        indexMap[c] = tail;
    }

    return maxlen;
}