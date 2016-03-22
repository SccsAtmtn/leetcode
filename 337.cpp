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
    unordered_map<TreeNode *, pair<int, int>> f;
    int rob(TreeNode* root) {
        if (!root) return 0;
        searchTree(root);
        auto ptr = f.find(root);
        return max(ptr->second.first, ptr->second.second);
    }
    void searchTree(TreeNode * root) {
        if (!root) return;
        searchTree(root->left);
        searchTree(root->right);
        pair<int, int> node(root->val, 0);
        auto left = root->left, right = root->right;
        int leftVal1 = 0, leftVal2 = 0, rightVal1 = 0, rightVal2 = 0;
        if (left) {
            auto ptr = f.find(left);
            leftVal1 = ptr->second.second;
            leftVal2 = max(ptr->second.first, ptr->second.second);
        }
        if (right) {
            auto ptr = f.find(right);
            rightVal1 = ptr->second.second;
            rightVal2 = max(ptr->second.first, ptr->second.second);
        }
        node.first = root->val+leftVal1+rightVal1;
        node.second = leftVal2+rightVal2;
        f.insert(make_pair(root, node));
    }
};