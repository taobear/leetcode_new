#include "restoreIpAddresses.h"

#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backTrack(const char *s, char **ipAddr, int *ipAddrNum, char *tmpAddr, int tmpAddrLen, int level)
{
    if (level >= 4 && *s == '\0') {
        ipAddr[*ipAddrNum] = (char *)malloc(tmpAddrLen * sizeof(char));
        memcpy(ipAddr[*ipAddrNum], tmpAddr, tmpAddrLen - 1);
        ipAddr[*ipAddrNum][tmpAddrLen - 1] = '\0';
        *ipAddrNum = *ipAddrNum + 1;
        return;
    }

    if (level >= 4 || *s == '\0') {
        return;
    }

    int num = 0;
    int leftLength = strlen(s);
    int len = leftLength > 3 ? 3 : leftLength;
    for (int index = 0; index < len; ++index) {
        if (index > 0 && s[0] == '0') {
            break;
        }

        num = num * 10 + s[index] - '0';
        if (num > 255) {
            break;
        }

        tmpAddr[tmpAddrLen + index] = s[index];
        tmpAddr[tmpAddrLen + index + 1] = '.';
        backTrack(s + index + 1, ipAddr, ipAddrNum, tmpAddr, tmpAddrLen + index + 2, level + 1);
    }
}

char **restoreIpAddresses(char *s, int *returnSize)
{
    int len = strlen(s);
    char **ipAddr = (char **)malloc(1000 * sizeof(char *));
    int ipAddrNum = 0;

    char tmpAddr[len + 4];
    backTrack(s, ipAddr, &ipAddrNum, tmpAddr, 0, 0);

    *returnSize = ipAddrNum;
    return ipAddr;
}