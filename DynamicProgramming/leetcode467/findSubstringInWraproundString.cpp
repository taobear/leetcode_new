#include "findSubstringInWraproundString.h"

#include <string.h>

#define MAX_ASICII_SIZE 26

int findSubstringInWraproundString(char* p)
{
    int slen = strlen(p);
    if (slen <= 0) {
        return 0;
    }

    int cur = 1, sum = 1;
    int substrMaxLen[MAX_ASICII_SIZE] = {0};
    substrMaxLen[p[0] - 'a'] = 1;
    for (int j = 1; j < slen; j++) {
        if (p[j] - p[j - 1] == 1 || p[j] - p[j - 1] == -25) {
            cur += 1; 
        } else {
            cur = 1;
        }

        if (substrMaxLen[p[j] - 'a'] < cur) {
            sum += cur - substrMaxLen[p[j] - 'a'];
            substrMaxLen[p[j] - 'a'] = cur;
        }
    }

    return sum;
}