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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root==NULL) return ans;
        dfs(root, intToString(root->val));
        return ans;
    }
    string intToString(int x) {
        if (x==0) return "0";
        string ans = "";
        bool flag = false;
        if (x<0) {
            flag = true;
            x = -x;
        }
        while (x>0) {
            ans = (char)(x%10+48)+ans;
            x = x/10;
        }
        if (flag) ans = "-"+ans;
        return ans;
    }
    void dfs(TreeNode * node, string str) {
        if (node->left==NULL && node->right==NULL) {
            ans.push_back(str);
            return;
        }
        if (node->left!=NULL) 
            dfs(node->left, str+"->"+intToString(node->left->val));
        if (node->right!=NULL)
            dfs(node->right, str+"->"+intToString(node->right->val));
    }
};