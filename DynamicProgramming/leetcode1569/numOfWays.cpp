#include "numOfWays.h"

#include <stdlib.h>

#define NUMS_MAX 1001
#define MOD 1000000007

int g_Cmn[NUMS_MAX][NUMS_MAX];

typedef struct Tree {
    struct Tree* left;
    struct Tree* right;
    int value;
    int size;
} Tree;

void initNode(Tree* node, int val)
{
    if (node == NULL) {
        return;
    }

    node->left = NULL;
    node->right = NULL;
    node->value = val;
    node->size = 1;
}

void insert(Tree* root, int val)
{
    Tree* iter = root;
    while (true) {
        iter->size++;
        if (val < iter->value) {
            if (iter->left == NULL) {
                iter->left = (Tree*)malloc(sizeof(Tree));
                initNode(iter->left, val);
                return;
            }

            iter = iter->left;
        } else {
            if (iter->right == NULL) {
                iter->right = (Tree*)malloc(sizeof(Tree));
                initNode(iter->right, val);
                return;
            }

            iter = iter->right;
        }
    }
}

Tree* buildTree(int* nums, int numsSize)
{
    Tree* root = (Tree*)malloc(sizeof(Tree));
    initNode(root, nums[0]);
    for (int i = 1; i < numsSize; i++) {
        insert(root, nums[i]);
    }

    return root;
}

void freeTree(Tree* root)
{
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int helper(Tree* root)
{
    if (root == NULL) {
        return 1;
    }

    long long leftSize = root->left ? root->left->size : 0;
    long long rightSize = root->right ? root->right->size : 0;
    if (leftSize + rightSize == 0) {
        return 1;
    }

    long long leftPossible = helper(root->left);
    long long rightPossible = helper(root->right);
    return (leftPossible * ((rightPossible * g_Cmn[leftSize + rightSize][leftSize]) % MOD)) % MOD;
}

int numOfWays(int* nums, int numsSize)
{
    if (numsSize <= 1) {
        return 0;
    }

    for (int i = 0; i <= numsSize; i++) {
        g_Cmn[i][0] = g_Cmn[i][i] = 1;
        for (int j = 1; j < i; j++) {
            g_Cmn[i][j] = (g_Cmn[i - 1][j] + g_Cmn[i - 1][j - 1]) % MOD;
        }
    }

    Tree* root = buildTree(nums, numsSize);
    int result = (helper(root) + MOD - 1) % MOD;
    freeTree(root);
    return result;
}