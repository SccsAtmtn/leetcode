#include "head.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        if (n==0)
            return nullptr;
        return buildSubTree(inorder, postorder, 0, n, n-1);
    }

    TreeNode *buildSubTree(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postEnd) {
        if (inStart==inEnd) 
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        for (int i=inStart; i<inEnd; ++i)
            if (inorder[i]==postorder[postEnd]) {
                root->left = buildSubTree(inorder, postorder, inStart, i, postEnd-1-(inEnd-i-1));
                root->right = buildSubTree(inorder, postorder, i+1, inEnd, postEnd-1);
                break;
            }
        return root;
    }
};
