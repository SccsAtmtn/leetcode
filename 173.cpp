#include "head.h"

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    bool hasNext() {
        return !(stk.empty());
    }

    int next() {
        TreeNode *currentNode = stk.top();
        int ans = currentNode->val;
        stk.pop();
        currentNode = currentNode->right;
        while (currentNode) {
            stk.push(currentNode);
            currentNode = currentNode->left;
        }
        return ans;
    }
private:
    stack<TreeNode *> stk;
};
