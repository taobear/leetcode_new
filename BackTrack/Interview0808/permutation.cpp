#include "permutation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_MAX_SIZE 128
#define PERMUTATION_MAX 10000000

void backTrack(int *allCount, int *tmpCount, int lengthOfString, char **result, int *resultNum, char *pathTrack, int pathLevel)
{
    if (lengthOfString == pathLevel) {
        result[*resultNum] = (char *)malloc(sizeof(char) * (lengthOfString + 1));
        strcpy(result[*resultNum], pathTrack);
        *resultNum = *resultNum + 1;
        return;
    }

    for (int index = 0; index < CHAR_MAX_SIZE; ++index) {
        if (tmpCount[index] >= allCount[index]) {
            continue;
        }

        pathTrack[pathLevel] = index;
        tmpCount[index]++;
        backTrack(allCount, tmpCount, lengthOfString, result, resultNum, pathTrack, pathLevel + 1);
        tmpCount[index]--;
    }
}

char **permutation(char *S, int *returnSize)
{
    int slen = strlen(S);
    if (slen <= 0) {
        *returnSize = 0;
        return NULL;
    }

    int allCount[CHAR_MAX_SIZE] = {0};
    for (int index = 0; index < slen; ++index) {
        allCount[S[index]]++;
    }

    int tmpCount[CHAR_MAX_SIZE] = {0};
    char *pathTrack = (char *)malloc(sizeof(char) * (slen + 1));
    pathTrack[slen] = '\0';

    char **result = (char **)malloc(PERMUTATION_MAX * sizeof(char *));
    int resultNum = 0;
    backTrack(allCount, tmpCount, slen, result, &resultNum, pathTrack, 0);

    free(pathTrack);
    *returnSize = resultNum;
    return result;
}