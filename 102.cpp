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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<vector<TreeNode *>> que;
        que.push_back(vector<TreeNode *>(1, root));
        int i = 0;
        while (i<que.size()) {
            vector<TreeNode *> temp;
            for (int j=0; j<que[i].size(); ++j) {
                TreeNode * node = que[i][j];
                if (node->left) 
                    temp.push_back(node->left);
                if (node->right)
                    temp.push_back(node->right);
            }
            if (!temp.empty())
                que.push_back(temp);
            ++i;
        }
        for (int i=0; i<que.size(); ++i) {
            ans.push_back(vector<int>());
            for (int j=0; j<que[i].size(); ++j)
                ans[i].push_back(que[i][j]->val);
        }
        return ans;
    }
};