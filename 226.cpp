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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) return root;
        invert(root);
        return root;
    }
    void invert(TreeNode* root) {
        TreeNode* node = root->left;
        root->left = root->right;
        root->right = node;
        if (root->left) invert(root->left);
        if (root->right) invert(root->right);
    }
};