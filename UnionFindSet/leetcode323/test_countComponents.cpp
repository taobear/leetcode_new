#include "countComponents.h"

#include <stdio.h>

void test1()
{
    int n = 5; 
    int edge1[] = {0, 1};
    int edge2[] = {1, 2};
    int edge3[] = {3, 4};

    int *edges[] = {edge1, edge2, edge3};
    int edgesSize = sizeof(edges) / sizeof(*edges);
    int edgesColSize[] = {2, 2, 2};
    printf("test1(): %d\n", countComponents(n, edges, edgesSize, edgesColSize));
}

void test2()
{
    int n = 5; 
    int edge1[] = {0, 1};
    int edge2[] = {1, 2};
    int edge3[] = {2, 3};
    int edge4[] = {3, 4};

    int *edges[] = {edge1, edge2, edge3, edge4};
    int edgesSize = sizeof(edges) / sizeof(*edges);

    int edgesColSize[] = {2, 2, 2, 2};
    printf("test2(): %d\n", countComponents(n, edges, edgesSize, edgesColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}