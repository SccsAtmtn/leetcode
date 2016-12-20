#include "head.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        deque<TreeNode *> currentLevel, nextLevel;
        currentLevel.push_back(root);
        bool reverse = false;
        while (!currentLevel.empty()) {
            vector<int> numbers;
            while (!currentLevel.empty()) {
                TreeNode *node = currentLevel.back();
                numbers.push_back(node->val);
                if (!reverse) {
                    if (node->left)
                        nextLevel.push_back(node->left);
                    if (node->right)
                        nextLevel.push_back(node->right);
                }
                else {
                    if (node->right)
                        nextLevel.push_back(node->right);
                    if (node->left)
                        nextLevel.push_back(node->left);
                }
                currentLevel.pop_back();
            }
            ans.push_back(numbers);
            currentLevel.swap(nextLevel);
            reverse = !reverse;
        }
        return ans;
    }
};
