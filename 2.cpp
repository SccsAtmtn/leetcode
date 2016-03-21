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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * node0 = NULL, * node1 = l1, * node2 = l2, * head = NULL;
        int rest = 0;
        while (node1 && node2) {
            int sum = rest+node1->val+node2->val;
            if (!head) {
                node0 = new ListNode(sum%10);
                head = node0;
            }
            else {
                node0->next = new ListNode(sum%10);
                node0 = node0->next;
            }
            rest = sum/10;
            node1 = node1->next;
            node2 = node2->next;
        }
        while (node1) {
            int sum = rest+node1->val;
            if (!head) {
                node0 = new ListNode(sum%10);
                head = node0;
            }
            else {
                node0->next = new ListNode(sum%10);
                node0 = node0->next;
            }
            rest = sum/10;
            node1 = node1->next;
        }
        while (node2) {
            int sum = rest+node2->val;
            if (!head) {
                node0 = new ListNode(sum%10);
                head = node0;
            }
            else {
                node0->next = new ListNode(sum%10);
                node0 = node0->next;
            }
            rest = sum/10;
            node2 = node2->next;
        }
        if (rest>0) {
            if (!head) {
                node0 = new ListNode(rest);
                head = node0;
            }
            else {
                node0->next = new ListNode(rest);
                node0 = node0->next;
            }
        }
        return head;
    }
};