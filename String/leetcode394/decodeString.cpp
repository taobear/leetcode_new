#include "decodeString.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

int g_dupNums[MAX_STR_LEN];
int g_dupStart[MAX_STR_LEN];
int g_dupSize;

char * decodeString(char *s)
{
    if (s == NULL) {
        return NULL;
    }

    char *result = (char*)malloc(MAX_STR_LEN * sizeof(char));

    g_dupSize = 0;
    int retLen = 0;
    int dupNum = 0;

    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == '[') { // in stack
            g_dupStart[g_dupSize] = retLen;
            g_dupNums[g_dupSize] = dupNum;

            dupNum = 0;
            g_dupSize++;
        } else if (s[i] == ']') { // out stack
            int topNum = g_dupNums[g_dupSize - 1];
            int topStart = g_dupStart[g_dupSize - 1];

            int start = retLen;
            for (int n = 1; n < topNum; ++n) {
                for (int s = topStart; s < retLen; ++s) {
                    result[start++] = result[s];
                }
            }

            retLen = start;
            g_dupSize--;
        } else if (s[i] >= '0' && s[i] <= '9') {
            dupNum = dupNum * 10 + s[i] - '0';
        } else {
            result[retLen ++] = s[i];
        }
    }

    result[retLen] = '\0';
    return result;
}