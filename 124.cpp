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
    int ans;
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        ans = 0x80000000;
        treeDP(root);
        return ans;
    }
    int treeDP(TreeNode * root) {
        TreeNode * left = root->left, * right = root->right;
        int leftMax = 0, rightMax = 0;
        if (left)
            leftMax = max(leftMax, treeDP(left));
        if (right)
            rightMax = max(rightMax, treeDP(right));
        ans = max(ans, leftMax+root->val+rightMax);
        return max(leftMax, rightMax)+root->val;
    }
};