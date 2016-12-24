#include "head.h"

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        int ans = 0;
        searchPath(root, ans, 0);
        return ans;
    }

    void searchPath(TreeNode *root, int &ans, int currentNum) {
        currentNum = currentNum*10+root->val;
        if (!root->left && !root->right) {
            ans += currentNum;
            return;
        }
        if (root->left)
            searchPath(root->left, ans, currentNum);
        if (root->right)
            searchPath(root->right, ans, currentNum);
    }
};
