#include "removeDuplicateLetters.h"

#include <string.h>
#include <stdlib.h>

#define MAX_ASCII_SIZE 26

char* removeDuplicateLetters(char* s)
{
    int slen = strlen(s);
    int leftCharCnt[MAX_ASCII_SIZE] = { 0 };
    int existChar[MAX_ASCII_SIZE] = { 0 };
    for (int i = 0; i < slen; i++) {
        leftCharCnt[s[i] - 'a']++;
    }

    char* retStr = (char*)malloc((slen + 1) * sizeof(char));
    int retStrLen = 0;

    for (int i = 0; i < slen; i++) {
        leftCharCnt[s[i] - 'a']--;
        if (retStrLen == 0) {
            retStr[retStrLen++] = s[i];
            existChar[s[i] - 'a'] = 1;
            continue;
        }

        if (existChar[s[i] - 'a'] == 1) {
            continue;
        }

        while (retStrLen != 0 && 
               retStr[retStrLen - 1] > s[i] && 
               leftCharCnt[retStr[retStrLen - 1] - 'a'] > 0) {
            existChar[retStr[retStrLen - 1] - 'a'] = 0;
            retStrLen--;
        }

        retStr[retStrLen++] = s[i];
        existChar[s[i] - 'a'] = 1;
    }

    retStr[retStrLen] = '\0';
    return retStr;
}