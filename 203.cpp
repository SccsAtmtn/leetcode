/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head!=NULL && head->val==val) head = head->next;
        if (head==NULL) return NULL;
        ListNode* node = head->next, * pre = head;
        while (node!=NULL) {
            if (node->val==val) {
                pre->next = node->next;
                node = node->next;
                continue;
            }
            pre = node;
            node = node->next;
        }
        return head;
    }
};