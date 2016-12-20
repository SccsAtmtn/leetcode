#include "head.h"

class Solution {
public:
    const int MAX_INT = 0x7fffffff, MIN_INT=0x80000000;
    bool isValidBST(TreeNode *root) {
        int max = MAX_INT, min = MIN_INT;
        return validateBST(root, max, min);
    }
    bool validateBST(TreeNode *root, int &max, int &min) {
        if (!root) 
            return true;
        max = min = root->val;
        TreeNode *left = root->left;
        if (left) {
            int leftMin = MAX_INT, leftMax = MIN_INT;
            bool isBST = validateBST(left, leftMax, leftMin);
            if (!isBST || leftMax>=root->val)
                return false;
            min = leftMin;
        }
        TreeNode *right = root->right;
        if (right) {
            int rightMin = MAX_INT, rightMax = MIN_INT;
            bool isBST = validateBST(right, rightMax, rightMin);
            if (!isBST || rightMin<=root->val)
                return false;
            max = rightMax;
        }
        return true;
    }
};
