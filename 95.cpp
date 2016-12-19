#include "head.h"

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> ans;
        if (n==0)
            return ans;
        vector<bool> used(n, false);
        return dfsGenerate(used, 0, n);
    }

    vector<TreeNode *> dfsGenerate(vector<bool> &used, int start, int end) {
        vector<TreeNode *> ans;
        for (int i=start; i<end; ++i)
            if (!used[i]) {
                used[i] = true;
                vector<TreeNode *> left = dfsGenerate(used, start, i);
                vector<TreeNode *> right = dfsGenerate(used, i+1, end);
                if (left.empty())
                    left.push_back(nullptr);
                if (right.empty())
                    right.push_back(nullptr);
                for (TreeNode *leftSon : left)
                    for (TreeNode *rightSon : right) {
                        TreeNode *root = new TreeNode(i+1);
                        root->left = leftSon;
                        root->right = rightSon;
                        ans.push_back(root);
                    }
                used[i] = false;
            }
        return ans;
    }
};
