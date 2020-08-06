#include "permutation.h"

#include <stdio.h>

void test1()
{
    char S[] = "qqe";

    int returnSize;
    char **result = permutation(S, &returnSize);

    printf("test1(): \n");
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
    }
}

void test2()
{
    char S[] = "ab";

    int returnSize;
    char **result = permutation(S, &returnSize);

    printf("test2(): \n");
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
    }
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}