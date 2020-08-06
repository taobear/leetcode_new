#include "maximizeSweetness.h"

#include <limits.h>
#include <stdlib.h>

int getMinSweetness(int *sweetness, int sweetnessSize)
{
    if (sweetness == NULL || sweetnessSize == 0)
    {
        return 0;
    }

    int result = INT_MAX;
    for (int i = 0; i < sweetnessSize; ++i)
    {
        result = result > sweetness[i] ? sweetness[i] : result;
    }

    return result;
}

int getSumSweetness(int *sweetness, int sweetnessSize)
{
    if (sweetness == NULL || sweetnessSize == 0)
    {
        return 0;
    }

    int result = 0;
    for (int i = 0; i < sweetnessSize; ++i)
    {
        result += sweetness[i];
    }

    return result;
}

bool canAffordCandy(int *sweetness, int sweetnessSize, int K, int candy)
{
    if (sweetness == NULL || sweetnessSize == 0)
    {
        return false;
    }

    int kcnt = 0;
    int sumCandy = 0;
    for (int i = 0; i < sweetnessSize; ++i)
    {
        sumCandy += sweetness[i];
        if (sumCandy >= candy)
        {
            sumCandy = 0;
            kcnt++;
        }

        if (kcnt > K + 1)
        {
            break;
        }
    }

    return kcnt >= K + 1;
}

int getMaxMinCandy(int *sweetness, int sweetnessSize, int K, int candy)
{
    if (sweetness == NULL || sweetnessSize == 0)
    {
        return false;
    }

    int sumCandy = 0;
    int minCandy = INT_MAX;
    for (int i = 0; i < sweetnessSize; ++i)
    {
        sumCandy += sweetness[i];
        if (sumCandy >= candy)
        {
            minCandy = sumCandy > minCandy ? minCandy : sumCandy;
            sumCandy = 0;
        }
    }

    return minCandy;
}

int maximizeSweetness(int *sweetness, int sweetnessSize, int K)
{
    if (sweetness == NULL || sweetnessSize == 0)
    {
        return 0;
    }

    int left = getMinSweetness(sweetness, sweetnessSize);
    int sumSweetness = getSumSweetness(sweetness, sweetnessSize);
    int right = sumSweetness / (K + 1) + 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        bool afford = canAffordCandy(sweetness, sweetnessSize, K, mid);
        if (afford == true)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return getMaxMinCandy(sweetness, sweetnessSize, K, left - 1);
}