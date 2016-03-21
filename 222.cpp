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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = count(root->left);
        int rightHeight = count(root->right);
        if (leftHeight==rightHeight)
            return (1<<leftHeight)+countNodes(root->right);
        else
            return (1<<rightHeight)+countNodes(root->left);
    }
    int count(TreeNode* root) {
        if (!root) return 0;
        return 1+count(root->left);
    }
};