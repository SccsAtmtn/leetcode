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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        pair<int, bool> result = judge(root);
        return result.second;
    }
    pair<int, bool> judge(TreeNode * root) {
        if (!root) return make_pair(0, true);
        pair<int, bool> left = judge(root->left);
        if (!left.second) return make_pair(0, false);
        pair<int, bool> right = judge(root->right);
        if (!right.second) return make_pair(0, false);
        if (abs(left.first-right.first)<=1) 
            return make_pair(max(left.first, right.first)+1, true);
        else
            return make_pair(-1, false);
    }
};