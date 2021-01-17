#include "minCost.h"

int min(int a, int b)
{
    return a < b ? a : b;
}

int minCost(int** costs, int costsSize, int* costsColSize)
{
    int red = 0;
    int blue = 0;
    int green = 0;

    for (int index = 0; index < costsSize; index++) {
        int tr = min(blue, green) + costs[index][0];
        int tb = min(red, green) + costs[index][1];
        int tg = min(red, blue) + costs[index][2];

        red = tr;
        blue = tb;
        green = tg;
    }

    return min(red, min(blue, green));
}