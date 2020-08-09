#include "func_2d_objs.h"

#include <stdio.h>
#include <stdlib.h>

void print_2d_nums(int **subset, int subsetNum, int *subsetSize)
{
    printf("[\n");

    for (int index = 0; index < subsetNum; ++index)
    {
        printf("  [");

        for (int j = 0; j < subsetSize[index] - 1; ++j)
        {
            printf("%d, ", subset[index][j]);
        }
        if (subsetSize[index] - 1 >= 0)
        {
            printf("%d", subset[index][subsetSize[index] - 1]);
        }

        printf("]\n");
    }

    printf("]\n");
}

void free_2d_nums(int **subset, int subsetNum, int *subsetSize)
{
    for (int index = 0; index < subsetNum; ++index)
    {
        free(subset[index]);
    }

    free(subset);
    free(subsetSize);
}

void print_2d_str(char **substr, int substrNum)
{
    printf("[\n");

    for (int index = 0; index < substrNum - 1; ++index)
    {
        printf("  \"%s\",\n", substr[index]);
    }

    printf("  \"%s\"\n", substr[substrNum - 1]);
    printf("]\n");
}

void free_2d_str(char **substr, int substrNum)
{
    for (int index = 0; index < substrNum; ++index) {
        free(substr[index]);
    }
    free(substr);
}
