#include "head.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<pair<TreeNode *, int>> nodes;
        nodes.push(make_pair(root, 0));
        while (!nodes.empty()) {
            TreeNode *currentNode = nodes.top().first;
            int &status = nodes.top().second;
            if (status==0) {
                ans.push_back(currentNode->val);
                if (currentNode->left) 
                    nodes.push(make_pair(currentNode->left, 0));
                status = 1;
            }
            else if (status==1) {
                if (currentNode->right)
                    nodes.push(make_pair(currentNode->right, 0));
                status = 2;
            }
            else
                nodes.pop();
        }
        return ans;
    }
};
