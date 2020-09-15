#include "removeKdigits.h"

#include <stdlib.h>
#include <string.h>

char * removeKdigits(char * num, int k)
{
    int nlen = strlen(num);
    char *res = (char *)malloc(sizeof(char) * (nlen + 1));
    if (res == NULL) {
        return NULL;
    }

    int resLen = nlen - k;
    int resItr = 0;
    int zeroStartNum = 0;

    for (int i = 0; i < nlen; i++) {
        while (resItr != 0 && nlen - i > resLen - resItr && 
               res[resItr - 1] > num[i]) {
            resItr--;
        }

        res[resItr++] = num[i];
    }

    for (int i = 0; i < resLen; i++) {
        if (res[i] != '0') {
            break;
        }

        zeroStartNum++;
    }

    if (zeroStartNum != 0 && resLen != zeroStartNum) {
        memmove(res, res + zeroStartNum, resLen - zeroStartNum);
    }

    if (resLen == zeroStartNum || resLen == 0) {
        res[0] = '0';
        resLen = 1;
        zeroStartNum = 0;
    }

    res[resLen - zeroStartNum] = '\0';
    return res;
}