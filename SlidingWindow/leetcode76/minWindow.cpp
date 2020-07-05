#include "minWindow.h"

#include <string.h>
#include <limits.h>
#include <stdlib.h>

const int sizeOfAscii = CHAR_MAX + 1;
int sourceCnt[sizeOfAscii];
int targetCnt[sizeOfAscii];

char * minWindow(char * s, char * t)
{
    if (s == NULL || t == NULL) {
        return NULL;
    }

    int len = 0, minlen = INT_MAX;
    int slen = strlen(s);
    int tlen = strlen(t);

    memset(sourceCnt, 0, sizeof(int) * sizeOfAscii);
    memset(targetCnt, 0, sizeof(int) * sizeOfAscii);

    for (int i = 0; i < tlen; ++i) {
        targetCnt[t[i]] ++;
    }

    int head = 0, minhead = 0, tarlen = 0;
    for (int tail = 0; tail < slen; ++tail) {
        char c = s[tail];
        sourceCnt[c] ++;

        if (targetCnt[c] == 0) {  // 如果加入字符
            continue;
        }

        if (sourceCnt[c] <= targetCnt[c]) {
            tarlen ++;
        }

        int i = head;
        for ( ; i < tail; ++i) {
            if (sourceCnt[s[i]] <= targetCnt[s[i]]) {
                break;
            }

            sourceCnt[s[i]] --;
        }

        head = i;
        len = tail - head + 1;
        if (tarlen == tlen && len < minlen) {
            minhead = head;
            minlen = len;
        }
    }

    char *ret;
    if (minlen != INT_MAX) {
        ret = (char*)malloc((minlen + 1) * sizeof(char));
        strncpy(ret, s + minhead, minlen);
        ret[minlen] = '\0';
    } else {
        ret = (char*)malloc(1 * sizeof(char));
        ret[0] = '\0';
    }

    return ret;
}