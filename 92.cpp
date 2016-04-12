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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return head;
        if (m==n) return head;
        ListNode * pre = NULL, * succ = NULL;
        ListNode * cur = head;
        int tot = 1;
        while (tot<m) {
            pre = cur;
            cur = cur->next;
            ++tot;
        }
        ListNode * head1 = cur, * next = cur->next;
        while (tot<n && next) {
            ListNode * next1 = next->next;
            next->next = cur;
            cur = next;
            next = next1;
            ++tot;
        }
        succ = next;
        head1->next = succ;
        if (pre)
            pre->next = cur;
        else 
            head = cur;
        return head;
    }
};