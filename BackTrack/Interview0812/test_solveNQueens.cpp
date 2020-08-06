#include "solveNQueens.h"

#include <stdio.h>
#include <stdlib.h>

void print_nQueens(char ***nQueens, int nQueensNum, int *nQueensSize)
{
    printf("[\n");
    for (int index = 0; index < nQueensNum; ++index) {
        printf(" [\n");
        for (int j = 0; j < nQueensSize[index]; ++j) {
            printf("  %s\n", nQueens[index][j]);
        }
        printf(" ]\n\n");
    }
    printf("]\n");
}

void free_nQueens(char ***nQueens, int nQueensNum, int *nQueensSize) 
{
    for (int index = 0; index < nQueensNum; ++index) {
        for (int j = 0; j < nQueensSize[index]; ++j) {
            free(nQueens[index][j]);
        }
        free(nQueens[index]);
    }
    free(nQueens);
}

void test1()
{
    int n = 4;
    int returnSize;
    int *returnColumSize;

    char ***nQueens = solveNQueens(n, &returnSize, &returnColumSize);

    print_nQueens(nQueens, returnSize, returnColumSize);
    free_nQueens(nQueens, returnSize, returnColumSize);
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}