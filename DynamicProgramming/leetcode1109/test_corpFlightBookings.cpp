#include "corpFlightBookings.h"

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
    int booking1[] = {1, 2, 10};
    int booking2[] = {2, 3, 20};
    int booking3[] = {2, 5, 25};

    int *bookings[] = {booking1, booking2, booking3};
    int bookingsSize = sizeof(bookings) / sizeof(*bookings);
    int bookingsColSize[] = {3, 3, 3};
    int n = 5;

    int *ret, retSize;
    ret = corpFlightBookings(bookings, bookingsSize, bookingsColSize, n, &retSize);

    print_1d_nums(ret, retSize);
    free(ret);
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}