#include "minSwap.h"

#include <stdio.h>

void test1()
{
    int A[] = {1, 3, 5, 4};
    int B[] = {1, 2, 3, 7};

    int ASize = sizeof(A) / sizeof(*A);
    int BSize = sizeof(B) / sizeof(*B);
    

    printf("test1(): %d\n", minSwap(A, ASize, B, BSize));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}