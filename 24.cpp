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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        ListNode * first = head, * second = head->next, * pre = NULL;
        while (second) {
            if (pre) pre->next = second;
            else head = second;
            pre = first;
            ListNode * temp = second->next;
            second->next = first;
            first = temp;
            if (first) second = first->next;
            else second = NULL;
        }
        if (pre) pre->next = first;
        return head;
    }
};