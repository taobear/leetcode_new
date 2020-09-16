#include "maxNumber.h"

#include <string.h>
#include <stdlib.h>

void selectMaxSeqX(int* nums, int numsSize, int x, int* dest)
{
    int destSize = 0; // init mono dec stack
    for (int i = 0; i < numsSize; i++) {
        while ((destSize != 0) && (nums[i] > dest[destSize - 1]) && // 维护单调递减栈
            (numsSize - i - 1 + destSize >= x)) { // 栈中元素 + 剩余元素 >= x
            destSize--;
        }

        dest[destSize++] = nums[i];
    }
}

bool isLargerSeq(int* nums1, int* nums2, int compareSize)
{
    for (int i = 0; i < compareSize; i++) {
        if (nums1[i] == nums2[i]) {
            continue;
        }

        return nums1[i] > nums2[i];
    }

    return false;
}

void mergeMaxSeq(int* nums1, int nums1Size, int* nums2, int nums2Size,
    int* dest)
{
    int i = 0;
    int j = 0;
    int destSize = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            dest[destSize] = nums2[j++];
        } else if (nums1[i] > nums2[j]) {
            dest[destSize] = nums1[i++];
        } else {
            int l = i, r = j;
            while (l < nums1Size && r < nums2Size) {
                if (nums1[l] != nums2[r]) {
                    break;
                }

                l++;
                r++;
            }

            if (l == nums1Size) {
                dest[destSize] = nums2[j++];
            } else if (r == nums2Size) {
                dest[destSize] = nums1[i++];
            } else {
                if (nums1[l] < nums2[r]) {
                    dest[destSize] = nums2[j++];
                } else {
                    dest[destSize] = nums1[i++];
                }
            }
        }

        destSize++;
    }

    while (i < nums1Size)
        dest[destSize++] = nums1[i++];
    while (j < nums2Size)
        dest[destSize++] = nums2[j++];
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k,
    int* returnSize)
{
    if (k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* res = (int*)malloc(k * sizeof(int));

    int subSeq1[nums1Size + 1]; // in case of nums1Size == 0
    int subSeq2[nums2Size + 1];
    int mergeSeq[k];

    bool isCompared = false;
    for (int subSeq1Size = 0; subSeq1Size <= k; subSeq1Size++) {
        if (subSeq1Size > nums1Size) {
            continue;
        }

        int subSeq2Size = k - subSeq1Size;
        if (subSeq2Size > nums2Size) {
            continue;
        }

        if (subSeq1Size != 0) {
            selectMaxSeqX(nums1, nums1Size, subSeq1Size, subSeq1);
        }

        if (subSeq2Size != 0) {
            selectMaxSeqX(nums2, nums2Size, subSeq2Size, subSeq2);
        }

        mergeMaxSeq(subSeq1, subSeq1Size, subSeq2, subSeq2Size, mergeSeq);

        if (isCompared == false || isLargerSeq(mergeSeq, res, k)) {
            memcpy(res, mergeSeq, k * sizeof(int));
            isCompared = true;
        }
    }

    *returnSize = k;
    return res;
}