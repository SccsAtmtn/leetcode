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
    int kthSmallest(TreeNode* root, int k) {
        return findKth(root, k);
    }
    int findKth(TreeNode * current, int k) {
        int leftSize = 0, rightSize = 0;
        if (current->left!=NULL)
            leftSize = countTree(current->left);
        if (leftSize>=k) 
            return findKth(current->left, k);
        else
            if (leftSize+1==k)
                return current->val;
        if (current->right!=NULL)
            rightSize = countTree(current->right);
        if (leftSize+1+rightSize>=k)
            return findKth(current->right, k-leftSize-1);
        else
            return -1;
    }
    int countTree(TreeNode * current) {
        int leftSize = 0, rightSize = 0;
        if (current->left!=NULL)
            leftSize = countTree(current->left);
        if (current->right!=NULL)
            rightSize = countTree(current->right);
        return leftSize+1+rightSize;
    }
};