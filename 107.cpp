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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<vector<TreeNode *>> temp;
        temp.push_back(vector<TreeNode *>(1, root));
        int i = 0;
        while (i<temp.size()) {
            vector<TreeNode *> que;
            int j = temp.size()-1;
            for (int k=0; k<temp[i].size(); ++k) {
                TreeNode * current = temp[i][k];
                if (current->left)
                    que.push_back(current->left);
                if (current->right)
                    que.push_back(current->right);
            }
            if (!que.empty())
                temp.push_back(que);
            ++i;
        }
        for (int i=temp.size()-1; i>=0; --i) {
            ans.push_back(vector<int>());
            int k = ans.size()-1;
            for (int j=0; j<temp[i].size(); ++j)
                ans[k].push_back(temp[i][j]->val);
        }
        return ans;
    }
};