#include "assignBikes.h"

#include <stdio.h>

void test1()
{
    int worker1[] = {0, 0};
    int worker2[] = {2, 1};
    int *workers[] = {worker1, worker2};
    int workersSize = sizeof(workers) / sizeof(*workers);
    int workersColSize[] = {2, 2};

    int bike1[] = {1, 2};
    int bike2[] = {3, 3};
    int *bikes[] = {bike1, bike2};
    int bikesSize = sizeof(bikes) / sizeof(*bikes);
    int bikesColSize[] = {2, 2};

    printf("test1(): %d\n", assignBikes(workers, workersSize, workersColSize, bikes, bikesSize, bikesColSize));
}

void test2()
{
    int worker1[] = { 0, 0 };
    int worker2[] = { 1, 1 };
    int worker3[] = { 2, 0 };
    int* workers[] = { worker1, worker2, worker3 };
    int workersSize = sizeof(workers) / sizeof(*workers);
    int workersColSize[] = { 2, 2, 2 };

    int bike1[] = { 1, 0 };
    int bike2[] = { 2, 2 };
    int bike3[] = { 2, 1 };
    int* bikes[] = { bike1, bike2, bike3 };
    int bikesSize = sizeof(bikes) / sizeof(*bikes);
    int bikesColSize[] = { 2, 2, 2 };

    printf("test2(): %d\n", assignBikes(workers, workersSize, workersColSize, bikes, bikesSize, bikesColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}