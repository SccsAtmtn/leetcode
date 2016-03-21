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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode * current = head;
        while (current) {
            if (!current->next || current->val!=current->next->val) 
                current = current->next;
            else
                current->next = current->next->next;
        }
        return head;
    }
};