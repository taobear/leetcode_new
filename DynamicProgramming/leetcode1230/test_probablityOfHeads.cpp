#include "probabilityOfHeads.h"

#include <stdio.h>

void test1()
{
    double prob[] = {0.4};
    int probSize = sizeof(prob) / sizeof(*prob);
    int target = 1;

    printf("test1(): %lf\n", probabilityOfHeads(prob, probSize, target));
}

void test2()
{
    double prob[] = { 0.5, 0.5, 0.5, 0.5, 0.5 };
    int probSize = sizeof(prob) / sizeof(*prob);
    int target = 0;

    printf("test2(): %lf\n", probabilityOfHeads(prob, probSize, target));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}