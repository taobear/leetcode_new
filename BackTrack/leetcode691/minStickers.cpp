#include "minStickers.h"

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

#define ALPHABETE_SIZE 26
#define STICKER_MAX_NUM 50

int g_charMap2Sticker[ALPHABETE_SIZE][STICKER_MAX_NUM];
int g_charMap2StickerIndex[ALPHABETE_SIZE][STICKER_MAX_NUM];
int g_charMap2StickerIndexSize[ALPHABETE_SIZE];

int g_stickerMap2CharCount[STICKER_MAX_NUM][ALPHABETE_SIZE];

int backTrack(int *target, int targetLen, int *targetMapIndex, int targetIndexLen, int level, int minLevel)
{
    if (level >= minLevel) {
        return minLevel;
    }

    if (targetLen == 0) {
        return level;
    }

    int result = minLevel;
    int charIndex = -1;
    for (int i = 0; i < targetIndexLen; ++i) {
        int index = targetMapIndex[i];
        if (target[index] != 0) {
            charIndex = index;
            break;
        }
    }

    int sticksCount = g_charMap2StickerIndexSize[charIndex];
    if (sticksCount == 0) {
        return minLevel;
    }

    int currTarget[ALPHABETE_SIZE];
    for (int j = 0; j < sticksCount; ++j) {
        int stickerId = g_charMap2StickerIndex[charIndex][j];
        int reduceLen = 0;
        for (int ki = 0; ki < targetIndexLen; ++ki) {
            int k = targetMapIndex[ki];

            currTarget[k] = target[k];                
            if (currTarget[k] == 0) {
                continue;
            }

            int tmpRedLen = currTarget[k] > g_stickerMap2CharCount[stickerId][k] ? 
                g_stickerMap2CharCount[stickerId][k] : currTarget[k];
            currTarget[k] -= tmpRedLen;
            reduceLen += tmpRedLen;
        }

        int tmpLevel = backTrack(currTarget, targetLen - reduceLen, targetMapIndex, targetIndexLen, level + 1, minLevel);
        result = tmpLevel > result ? result : tmpLevel;
    }

    return result;
}

void buildCharMap2Sticker(char **stickers, int stickersSize, int *targetMap)
{
    for (int index = 0; index < ALPHABETE_SIZE; ++index) {
        g_charMap2StickerIndexSize[index] = 0;
    }

    for (int index = 0; index < stickersSize; ++index) {
        int stickerlen = strlen(stickers[index]);
        for (int j = 0; j < stickerlen; ++j) {
            int charIndex = stickers[index][j] - 'a';
            if (targetMap[charIndex] == 0) {
                continue;
            }

            int stikCount = g_charMap2StickerIndexSize[charIndex];
            if (stikCount != 0 && g_charMap2Sticker[charIndex][stikCount - 1] == index) {
                continue;
            }

            g_charMap2Sticker[charIndex][stikCount] = index;
            g_charMap2StickerIndexSize[charIndex] = stikCount + 1;
        }
    }
}

void buildCharMap2StickerIndex(int stickersSize, int *isStickerValid)
{
    for (int index = 0; index < ALPHABETE_SIZE; ++index) {
        int stickCount = g_charMap2StickerIndexSize[index];
        int realStkCnt = 0;
        for (int j = 0; j < stickCount; ++j) {
            int stickerId = g_charMap2Sticker[index][j];
            if (isStickerValid[stickerId] != 1) {
                continue;
            }

            g_charMap2StickerIndex[index][realStkCnt] = g_charMap2Sticker[index][j];
            realStkCnt++;
        }
        g_charMap2StickerIndexSize[index] = realStkCnt;
    }
}

void buildStickerMap2CharCount(char **stickers, int stickersSize, int *targetMap)
{
    for (int index = 0; index < stickersSize; ++index) {
        memset(g_stickerMap2CharCount[index], 0, ALPHABETE_SIZE * sizeof(int));

        int stickerlen = strlen(stickers[index]);
        for (int j = 0; j < stickerlen; ++j) {
            int charIndex = stickers[index][j] - 'a';
            if (targetMap[charIndex] == 0) {
                continue;
            }

            g_stickerMap2CharCount[index][charIndex]++;
        }
    }
}

void uniqueStickerMapWithTarget(int stickersSize, int *targetMapIndex, int indexLen, int *isStickerValid)
{
    for (int i = 0; i < stickersSize; ++i) {
        isStickerValid[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (isStickerValid[j] != 1) {
                continue;
            }

            int state = 0;
            for (int k = 0; k < indexLen; ++k) {
                int kIndex = targetMapIndex[k];
                if (g_stickerMap2CharCount[j][kIndex] < g_stickerMap2CharCount[i][kIndex]) {
                    if (state == 0) {
                        state = 1;
                    } else if (state == -1) {
                        state = 2;
                        break;
                    } 
                } else if (g_stickerMap2CharCount[j][kIndex] > g_stickerMap2CharCount[i][kIndex]) {
                    if (state == 0) {
                        state = -1;
                    } else if (state == 1) {
                        state = 2;
                        break;
                    }
                }
            }

            if (state == 2) {
                continue;
            }
            
            if (state == 1 || state == 0) { // remove j
                isStickerValid[j] = 0;
            } else { // remove i
                isStickerValid[i] = 0;
                break;
            }
        }
    }
}


int buildTargetMap(char *target, int *targetMapCount)
{
    memset(targetMapCount, 0, sizeof(int) * ALPHABETE_SIZE);

    int tarlen = strlen(target);
    for (int i = 0; i < tarlen; ++i) {
        int charIndex = target[i] - 'a';
        targetMapCount[charIndex]++;
    }

    return tarlen;
}

int buildTargetMapIndex(int *targetMapCount, int *targetMapIndex)
{
    int indexLen = 0;
    for (int i = 0; i < ALPHABETE_SIZE; ++i) {
        if (targetMapCount[i] == 0) {
            continue;
        }

        targetMapIndex[indexLen++] = i;
    }

    return indexLen;
}

bool preCheckTarget(int *targetMapIndex, int indexLen)
{
    for (int i = 0; i < indexLen; ++i) {
        int index = targetMapIndex[i];
        if (g_charMap2StickerIndexSize[index] == 0) {
            return false;
        }
    }

    return true;
}

int minStickers(char **stickers, int stickersSize, char *target)
{
    int targetMapCount[ALPHABETE_SIZE];
    int targetLen = buildTargetMap(target, targetMapCount);

    int targetMapIndex[ALPHABETE_SIZE];
    int targetIndexLen = buildTargetMapIndex(targetMapCount, targetMapIndex);

    buildCharMap2Sticker(stickers, stickersSize, targetMapCount);
    if (preCheckTarget(targetMapIndex, targetIndexLen) != true) {
        return -1;
    }

    buildStickerMap2CharCount(stickers, stickersSize, targetMapCount);

    int isStickerValid[STICKER_MAX_NUM];
    uniqueStickerMapWithTarget(stickersSize, targetMapIndex, targetIndexLen, isStickerValid);

    buildCharMap2StickerIndex(stickersSize, isStickerValid);

    int minLevel = backTrack(targetMapCount, targetLen, targetMapIndex, targetIndexLen, 0, INT_MAX);
    return minLevel == INT_MAX ? -1 : minLevel;
}