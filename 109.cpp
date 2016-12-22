#include "head.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *currentNode = head;
        while (currentNode) {
            ++n;
            currentNode = currentNode->next;
        }
        return buildTree(head, n);
    }

    TreeNode *buildTree(ListNode *head, int len) {
        if (len==0)
            return nullptr;
        int cnt = 0;
        ListNode *currentNode = head;
        while (cnt<len/2) {
            ++cnt;
            currentNode = currentNode->next;
        }
        TreeNode *root = new TreeNode(currentNode->val);
        root->left = buildTree(head, cnt);
        root->right = buildTree(currentNode->next, len-cnt-1);
        return root;
    }
};
