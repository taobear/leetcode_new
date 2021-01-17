#include "minRefuelStops.h"

#include <stdio.h>
#include <stdlib.h>

void test1()
{
    int target = 1;
    int startFuel = 1;
    
    int *stations[] = {};
    int stationsSize = 0;

    printf("test1(): %d\n", minRefuelStops(target, startFuel, stations, stationsSize, NULL));
}

void test2()
{
    int target = 100;
    int startFuel = 1;

    int station1[] = {10, 100};
    int* stations[] = {station1};
    int stationsSize = sizeof(stations) / sizeof(*stations);

    int stationsColSize[] = {2};

    printf("test2(): %d\n", minRefuelStops(target, startFuel, stations, stationsSize, stationsColSize));
}

void test3()
{
    int target = 100;
    int startFuel = 10;

    int station1[] = { 10, 60 };
    int station2[] = { 20, 30 };
    int station3[] = { 30, 30 };
    int station4[] = { 60, 40 };

    int* stations[] = { station1, station2, station3, station4 };
    int stationsSize = sizeof(stations) / sizeof(*stations);

    int stationsColSize[] = { 2, 2, 2, 2 };

    printf("test3(): %d\n", minRefuelStops(target, startFuel, stations, stationsSize, stationsColSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}