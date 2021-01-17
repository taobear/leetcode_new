#include "oddEvenJumps.h"

#include <stdio.h>

void test1()
{
    int A[] = {10, 13, 12, 14, 15};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test1(): %d\n", oddEvenJumps(A, ASize));
}

void test2()
{
    int A[] = {2, 3, 1, 1, 4};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test2(): %d\n", oddEvenJumps(A, ASize));
}

void test3()
{
    int A[] = {5, 1, 3, 4, 2};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test3(): %d\n", oddEvenJumps(A, ASize));
}

void test4()
{
    int A[] = {1, 2, 3, 2, 1, 4, 4, 5};
    int ASize = sizeof(A) / sizeof(*A);

    printf("test4(): %d\n", oddEvenJumps(A, ASize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}