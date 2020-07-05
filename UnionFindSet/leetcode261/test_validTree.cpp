#include "validTree.h"

#include <stdio.h>

void test1()
{
    int edges1[] = {0, 1};
    int edges2[] = {0, 2};
    int edges3[] = {0, 3};
    int edges4[] = {1, 4};
    int *edges[] = {edges1, edges2, edges3, edges4};
    int edgesColSize[] = {2, 2, 2, 2};

    printf("test1(): %d\n", validTree(5, edges, 4, edgesColSize));
}

void test2()
{
    int edges1[] = {0, 1};
    int edges2[] = {1, 2};
    int edges3[] = {2, 3};
    int edges4[] = {1, 3};
    int edges5[] = {1, 4};
    int *edges[] = {edges1, edges2, edges3, edges4, edges5};
    int edgesColSize[] = {2, 2, 2, 2, 2};
    
    printf("test2(): %d\n", validTree(5, edges, 5, edgesColSize));
}

void test3()
{
    int edges1[] = {0, 1};
    int edges2[] = {2, 3};
    int *edges[] = {edges1, edges2};
    int edgesColSize[] = {2, 2};

    printf("test3(): %d\n", validTree(4, edges, 2, edgesColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}