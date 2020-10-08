#include "xorQueries.h"

#include <stdio.h>
#include <stdlib.h>

void print_1d_nums(int* nums, int numsSize)
{
    printf("[");
    for (int i = 0; i < numsSize - 1; ++i) {
        printf("%d, ", nums[i]);
    }

    printf("%d]\n", nums[numsSize - 1]);
}

void test1()
{
    int arr[] = {1, 3, 4, 8};
    int arrSize = sizeof(arr) / sizeof(*arr);
    int query1[] = {0, 1};
    int query2[] = {1, 2};
    int query3[] = {0, 3};
    int query4[] = {3, 3};
    int *queries[] = {query1, query2, query3, query4};
    int queriesSize = sizeof(queries) / sizeof(*queries);
    int queriesColSize[] = {2, 2, 2, 2};

    int *ret, retSize;
    ret = xorQueries(arr, arrSize, queries, queriesSize, queriesColSize, &retSize);

    print_1d_nums(ret, retSize);
    free(ret);
}

void test2()
{
    int arr[] = { 4, 8, 2, 10 };
    int arrSize = sizeof(arr) / sizeof(*arr);
    int query1[] = { 2, 3 };
    int query2[] = { 1, 3 };
    int query3[] = { 0, 0 };
    int query4[] = { 0, 3 };
    int* queries[] = { query1, query2, query3, query4 };
    int queriesSize = sizeof(queries) / sizeof(*queries);
    int queriesColSize[] = { 2, 2, 2, 2 };

    int *ret, retSize;
    ret = xorQueries(arr, arrSize, queries, queriesSize, queriesColSize, &retSize);

    print_1d_nums(ret, retSize);
    free(ret);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}