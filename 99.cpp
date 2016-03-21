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
    TreeNode * ptr1, * ptr2, * pre;
    void recoverTree(TreeNode* root) {
        ptr1 = ptr2 = pre = NULL;
        dfs(root);
        swap(ptr1->val, ptr2->val);
    }
    void dfs(TreeNode * node) {
        if (!node) return;
        if (node->left) dfs(node->left);
        if ((pre) && (pre->val>node->val)) {
            if (!ptr1) {
                ptr1 = pre;
                ptr2 = node;
            }
            else ptr2 = node;
        }
        pre = node;
        if (node->right) dfs(node->right);
    }
};