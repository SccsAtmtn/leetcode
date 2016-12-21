#include "head.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if (n==0)
            return nullptr;
        return buildSubTree(preorder, inorder, 0, 0, n);
    }
    TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder, int preStart, int inStart, int inEnd) {
        if (inStart==inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preStart]);
        for (int i=inStart; i<inEnd; ++i)
            if (inorder[i]==preorder[preStart]) {
                root->left = buildSubTree(preorder, inorder, preStart+1, inStart, i);
                root->right = buildSubTree(preorder, inorder, preStart+1+(i-inStart), i+1, inEnd);
            }
        return root;
    }
};
