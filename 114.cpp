#include "head.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root)
            return;
        dfsFlatten(root);
    }

    TreeNode *dfsFlatten(TreeNode *root) {
        if (!root->left && !root->right) 
            return root;
        TreeNode *rightSon = root->right;
        TreeNode *leftLastNode = (root->left)?dfsFlatten(root->left):nullptr;
        TreeNode *rightLastNode = (root->right)?dfsFlatten(root->right):nullptr;
        if (root->left) {
            root->right = root->left;
            root->left = nullptr;
            leftLastNode->right = rightSon;
        }
        return (rightLastNode)?rightLastNode:leftLastNode;
    }
};
