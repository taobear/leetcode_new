#include "NumArray.h"

NumArray* numArrayCreate(int* nums, int numsSize)
{
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    if (obj == NULL) {
        return obj;
    }

    obj->sumRangeNum = numsSize + 1;
    obj->sumRange = (int*)malloc(sizeof(int) * obj->sumRangeNum);
    obj->sumRange[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        obj->sumRange[i + 1] = obj->sumRange[i] + nums[i];
    }

    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j)
{
    return obj->sumRange[j + 1] - obj->sumRange[i];
}

void numArrayFree(NumArray* obj)
{
    if (obj == NULL) {
        return;
    }

    if (obj->sumRangeNum != 0) {
        free(obj->sumRange);
    }

    free(obj);
}