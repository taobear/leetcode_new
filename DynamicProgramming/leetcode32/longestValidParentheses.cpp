#include "longestValidParentheses.h"

#include <string.h>

int longestValidParentheses(char* s)
{
    int slen = strlen(s);
    int maxLen = 0;

    int stack[slen + 1];
    int top = -1;

    stack[++top] = -1;

    for (int index = 0; index < slen; index++) {
        if (s[index] == '(') {
            stack[++top] = index;
        } else {
            --top;
            if (top == -1) {
                stack[++top] = index;
            } else {
                maxLen = maxLen > index - stack[top] ? maxLen : index - stack[top];
            }
        }
    }

    return maxLen;
}