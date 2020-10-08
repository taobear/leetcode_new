#include "totalFruit.h"

int totalFruit(int* tree, int treeSize)
{
    if (treeSize <= 0) {
        return 0;
    }

    int basket1 = tree[0], basket2 = -1;
    int maxFruit = 1, curFruit = 1;
    int lastSameTree = 0;
    for (int j = 1; j < treeSize; j++) {
        if (basket1 == tree[j] || basket2 == tree[j]) {
            curFruit += 1;
        } else {
            if (basket1 == tree[j - 1]) {
                basket2 = tree[j];
            } else {
                basket1 = tree[j];
            }

            curFruit = j - lastSameTree + 1;
        }

        if (tree[j] != tree[j - 1]) {
            lastSameTree = j;
        }

        maxFruit = maxFruit > curFruit ? maxFruit : curFruit;
    }

    return maxFruit;
}