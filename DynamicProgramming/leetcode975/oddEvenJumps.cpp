#include "oddEvenJumps.h"

#include <stdlib.h>

typedef struct {
    int value;
    int index;
} JumpArr;

int jumpAscComp(const void *a, const void *b)
{
    const JumpArr *ja = (const JumpArr *)a;
    const JumpArr* jb = (const JumpArr *)b;

    if (ja->value == jb->value) {
        return ja->index - jb->index;
    }

    return ja->value - jb->value;
}

int jumpDecComp(const void *a, const void *b)
{
    const JumpArr *ja = (const JumpArr *)a;
    const JumpArr *jb = (const JumpArr *)b;

    if (ja->value == jb->value) {
        return ja->index - jb->index;
    }

    return jb->value - ja->value;
}

void findNextElement(JumpArr * arr, int num, int *next)
{
    int stack[num];
    int top = -1;

    for (int i = 0; i < num; i++) {
        next[i] = -1;
    }

    for (int i = 0; i < num; i++) {
        while (top != -1 && stack[top] < arr[i].index) {
            next[stack[top]] = arr[i].index; // 为什么不能把next的赋值放在 i 内，由于当前保持有序的是 index
            top--;
        }

        stack[++top] = arr[i].index;
    }
}

int oddEvenJumps(int* A, int ASize)
{
    JumpArr arr[ASize];
    for (int i = 0; i < ASize; i++) {
        arr[i].value = A[i];
        arr[i].index = i;
    }

    int nextGreater[ASize]; // 单调递减栈
    qsort(arr, ASize, sizeof(JumpArr), jumpAscComp);
    findNextElement(arr, ASize, nextGreater);

    int nextSmaller[ASize]; // 单调递增栈
    qsort(arr, ASize, sizeof(JumpArr), jumpDecComp);
    findNextElement(arr, ASize, nextSmaller);

    int result = 1;
    bool canJumpEnd[2][ASize];

    canJumpEnd[0][ASize - 1] = true;
    canJumpEnd[1][ASize - 1] = true;
    for (int i = ASize - 2; i >= 0; i--) {
        canJumpEnd[0][i] = nextGreater[i] >= 0 ? canJumpEnd[1][nextGreater[i]] : false;
        canJumpEnd[1][i] = nextSmaller[i] >= 0 ? canJumpEnd[0][nextSmaller[i]] : false;

        if (canJumpEnd[0][i] == true) {
            result++;
        }
    }

    return result;
}