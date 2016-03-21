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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* node = head->next, * node1;
        head->next = NULL;
        while (node!=NULL) {
            node1 = node->next;
            node->next = head;
            head = node;
            node = node1;
        }
        return head;
    }
};