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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode * preGroupHead = NULL, * groupHead = head, * ans = head;
        ListNode * current = NULL, * pre = NULL;
        int count;
        while (groupHead) {
            count = 1;
            current = groupHead->next;
            pre = groupHead;
            while ((current) && (count<k)) {
                ++count;
                ListNode * temp = current->next;
                current->next = pre;
                pre = current;
                current = temp;
            }
            if (count<k) {
                current = pre->next;
                pre->next = NULL;
                while ((current) && (current!=groupHead)) {
                    ListNode * temp = current->next;
                    current->next = pre;
                    pre = current;
                    current = temp;
                }
                current = groupHead;
                break;
            }
            if (preGroupHead) preGroupHead->next = pre;
            else ans = pre;
            preGroupHead = groupHead;
            groupHead = current;
        }
        if (preGroupHead)
            preGroupHead->next = current;
        return ans;
    }
};