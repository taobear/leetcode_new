#include "corpFlightBookings.h"

#include <stdlib.h>
#include <string.h>

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    int* ret = (int*)malloc(n * sizeof(int));
    memset(ret, 0, n * sizeof(int));

    for (int i = 0; i < bookingsSize; i++) {
        if (bookingsColSize[i] != 3) {
            free(ret);
            return NULL;
        }

        ret[bookings[i][0] - 1] += bookings[i][2];
        if (bookings[i][1] < n) {
            ret[bookings[i][1]] -= bookings[i][2];
        }
    }

    for (int i = 1; i < n; i++) {
        ret[i] += ret[i - 1];
    }

    *returnSize = n;
    return ret;
}