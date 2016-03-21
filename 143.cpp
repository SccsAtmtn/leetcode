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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode * current = head;
        int n = 0;
        while (current) {
            ++n;
            current = current->next;
        }
        if (n==1) return;
        int t = 0;
        current = head;
        ListNode * pre = NULL;
        while (t<(n+1)/2) {
            ++t;
            pre = current;
            current = current->next;
        }
        if (pre)
            pre->next = NULL;
        pre = current;
        current = current->next;
        pre->next = NULL;
        while (current) {
            ListNode * next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        ListNode * cur1 = head, * cur2 = pre;
        while (cur1 && cur2) {
            ListNode * next1 = cur1->next;
            ListNode * next2 = cur2->next;
            cur1->next = cur2;
            cur2->next = next1;
            cur1 = next1;
            cur2 = next2;
        }
    }
};