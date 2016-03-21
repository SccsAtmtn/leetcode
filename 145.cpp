/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return ans;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode * root) {
        TreeNode * left = root->left, * right = root->right;
        if (left) 
            dfs(left);
        if (right)
            dfs(right);
        ans.push_back(root->val);
    }
};