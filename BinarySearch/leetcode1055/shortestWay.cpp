#include "shortestWay.h"

#include <string.h>

#define ALPHA_BETA_NUM 26
#define INDEX_SIZE_MAX 10000

int g_indexMap[ALPHA_BETA_NUM][INDEX_SIZE_MAX];
int g_indexSizeMap[ALPHA_BETA_NUM];

void buildIndexMap(char *source)
{
    for (int ch = 0; ch < ALPHA_BETA_NUM; ++ch) {
        g_indexSizeMap[ch] = 0;
    }

    int len = strlen(source);
    for (int i = 0; i < len; ++i) {
        int srcCh = source[i] - 'a';
        if (srcCh < 0 || srcCh >= ALPHA_BETA_NUM) {
            continue;
        }

        g_indexMap[srcCh][g_indexSizeMap[srcCh]] = i;
        g_indexSizeMap[srcCh]++;
    }
}

int findUpperIndex(int *index, int num, int target)
{
    if (index == NULL || num == 0) {
        return -1;
    }

    int low = 0, high = num - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (index[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low == num ? -1 : index[low];
}

int shortestWay(char *source, char *target)
{
    int result = 0;
    int srclen = strlen(source);
    int tarlen = strlen(target);

    buildIndexMap(source);

    int srcId = -1, tarId = 0;
    while (tarId < tarlen) {
        int tarCh = target[tarId] - 'a';
        if (tarCh < 0 || tarCh >= ALPHA_BETA_NUM) {
            return -1;
        }

        int nextId = findUpperIndex(g_indexMap[tarCh], g_indexSizeMap[tarCh], srcId);
        if (srcId == nextId) {
            return -1;
        }

        if (nextId == -1) {
            result ++;
        } else {
            tarId ++;
        }

        srcId = nextId;
    }

    return result + 1;
}