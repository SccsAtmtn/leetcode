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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1, * cur2 = l2, * head = NULL, * current;
        while (cur1 && cur2) {
            if (!head) {
                head = new ListNode(0);
                current = head;
            } 
            else {
                current->next = new ListNode(0);
                current = current->next;
            }
            if (cur1->val<cur2->val) {
                current->val = cur1->val;
                cur1 = cur1->next;
            }
            else {
                current->val = cur2->val;
                cur2 = cur2->next;
            }
        }
        while (cur1) {
            if (!head) {
                head = new ListNode(cur1->val);
                current = head;
                cur1 = cur1->next;
            }
            else {
                current->next = new ListNode(cur1->val);
                current = current->next;
                cur1 = cur1->next;
            }
        }
        while (cur2) {
            if (!head) {
                head = new ListNode(cur2->val);
                current = head;
                cur2 = cur2->next;
            }
            else {
                current->next = new ListNode(cur2->val);
                current = current->next;
                cur2 = cur2->next;
            }
        }
        return head;
    }
};