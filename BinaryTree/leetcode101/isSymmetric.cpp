#include "isSymmetric.h"

bool isSymmetricTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isSymmetricTree(p->left, q->right) &&
           isSymmetricTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode *root)
{
    if (root == NULL) {
        return true;
    }

    return isSymmetricTree(root->left, root->right);
}