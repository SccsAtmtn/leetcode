#include "head.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> path;
        searchPath(ans, path, root, 0, sum);
        return ans;
    }

    void searchPath(vector<vector<int>> &ans, vector<int> &path, TreeNode *root, int sum, int target) {
        path.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum==target) 
                ans.push_back(path);
            path.pop_back();
            return;
        }
        if (root->left) 
            searchPath(ans, path, root->left, sum, target);
        if (root->right)
            searchPath(ans, path, root->right, sum, target);
        path.pop_back();
    }
};
