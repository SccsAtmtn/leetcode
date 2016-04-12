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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode * head1 = head->next;
        head->next = 0;
        while (head1) {
            ListNode * cur1 = head1;
            head1 = head1->next;
            cur1->next = 0;
            ListNode * cur = head, * pre = NULL;
            while (cur && cur->val<cur1->val) {
                pre = cur;
                cur = cur->next;
            }
            if (!cur)
                pre->next = cur1;
            else {
                if (pre) 
                    pre->next = cur1;
                else 
                    head = cur1;
                cur1->next = cur;
            }
        }
        return head;
    }
};