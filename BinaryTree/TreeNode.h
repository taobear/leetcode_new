#ifndef __TREE_NODE_H_
#define __TREE_NODE_H_

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

#endif