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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode * current = head;
        int len = 0;
        while (current) {
            ++len;
            current = current->next;
        }
        if (len<n) return head;
        int delta = len-n;
        current = head;
        ListNode * pre = NULL;
        while (delta>0) {
            --delta;
            pre = current;
            current = current->next;
        }
        if (!pre) return head->next;
        else {
            pre->next = current->next;
            return head;
        }
    }
};