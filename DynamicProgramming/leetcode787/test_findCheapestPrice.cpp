#include "findCheapestPrice.h"

void test1()
{
    int n = 3;
    int flights[3][3] = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int flightsSize = 3;
    int flightsColSize[] = {3, 3, 3};
    int src = 0, dst = 2, k = 1;

    int ret = findCheapestPrice(n, flights, flightsSize, flightsColSize, src, dst, k);
    printf("test1(): %d\n", ret);
}

void test2()
{
    int n = 3;
    int flights[3][3] = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int flightsSize = 3;
    int flightsColSize[] = {3, 3, 3};
    int src = 0, dst = 2, k = 0;

    int ret = findCheapestPrice(n, flights, flightsSize, flightsColSize, src, dst, k);
    printf("test2(): %d\n", ret);
}

int main(int argc, char **argv)
{
    test1();
    
    test2();

    return 0;
}