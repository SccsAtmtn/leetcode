#include "head.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (!root)
            return ans;
        dfs(ans, root, 1);
        return ans;
    }
    void dfs(vector<int> &ans, TreeNode *root, int depth) {
        if (depth<=ans.size()) 
            ans[depth-1] = root->val;
        else
            ans.push_back(root->val);
        if (root->left)
            dfs(ans, root->left, depth+1);
        if (root->right)
            dfs(ans, root->right, depth+1);
    }
};
