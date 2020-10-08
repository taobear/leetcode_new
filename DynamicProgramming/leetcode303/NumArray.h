#ifndef __NUM_ARRAY_H_
#define __NUM_ARRAY_H_

typedef struct {
    int* sumRange;
    int sumRangeNum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize);

int numArraySumRange(NumArray* obj, int i, int j);

void numArrayFree(NumArray* obj);

#endif