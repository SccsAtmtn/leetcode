/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        root->next = NULL;
        TreeLinkNode * head = root;
        while (true) {
            TreeLinkNode * current = head;
            while (current && !current->left && !current->right)
                current = current->next;
            if (!current) return;
            if (current->left) head = current->left;
            else head = current->right;
            TreeLinkNode * current1 = head;
            while (current1) {
                if (current->left==current1) {
                    if (current->right) current1->next = current->right;
                    else {
                        current = current->next;
                        while (current && !current->left && !current->right)
                            current = current->next;
                        if (!current) current1->next = NULL;
                        else
                            if (current->left) current1->next = current->left;
                            else current1->next = current->right;
                    }
                    current1 = current1->next;
                }
                else {
                    current = current->next;
                    while (current && !current->left && !current->right) 
                        current = current->next;
                    if (!current) current1->next = NULL;
                    else
                        if (current->left) current1->next = current->left;
                        else current1->next = current->right;
                    current1 = current1->next;
                }
            }
        }
    }
};