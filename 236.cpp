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
    vector<TreeNode *> pPath, qPath, Path;
    bool found;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        found = false;
        find(root, p);
        pPath = Path;
        found = false;
        Path.clear();
        find(root, q);
        qPath = Path;
        return search();
    }
    void find(TreeNode * node, TreeNode * p) {
        if (found) return;
        Path.push_back(node);
        if (node==p) {
            found = true;
            return;
        }
        if (node->left!=NULL) find(node->left, p);
        if (node->right!=NULL) find(node->right, p);
        if (!found)
            Path.pop_back();
    }
    TreeNode * search() {
        int minLen = min(pPath.size(), qPath.size());
        for (int i=0; i<minLen; ++i) {
            if (pPath[i]!=qPath[i]) return pPath[i-1];
        }
        return pPath[minLen-1];
    }
};