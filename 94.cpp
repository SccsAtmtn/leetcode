#include "head.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (!root)
            return ans;
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        for (int x:left)
            ans.push_back(x);
        ans.push_back(root->val);
        for (int x:right)
            ans.push_back(x);
        return ans;
    }
};
