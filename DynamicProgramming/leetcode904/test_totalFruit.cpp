#include "totalFruit.h"

#include <stdio.h>

void test1()
{
    int tree[] = {1, 2, 1};
    int treeSize = sizeof(tree) / sizeof(*tree);

    printf("test1(): %d\n", totalFruit(tree, treeSize));
}

void test2()
{
    int tree[] = {0, 1, 2, 2};
    int treeSize = sizeof(tree) / sizeof(*tree);

    printf("test2(): %d\n", totalFruit(tree, treeSize));
}

void test3()
{
    int tree[] = {1, 2, 3, 2, 2};
    int treeSize = sizeof(tree) / sizeof(*tree);

    printf("test3(): %d\n", totalFruit(tree, treeSize));
}

void test4()
{
    int tree[] = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    int treeSize = sizeof(tree) / sizeof(*tree);

    printf("test4(): %d\n", totalFruit(tree, treeSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}