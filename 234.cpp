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
    bool isPalindrome(ListNode* head) {
        if (head==NULL) return true;
        int len = 0;
        ListNode * node = head;
        while (node!=NULL) {
            ++len;
            node = node->next;
        }
        return judge(head, len, node);
    }
    bool judge(ListNode* head, int len, ListNode*& node) {
        if (len==1) {
            node = head->next;
            return true;
        }
        if (len==2) {
            node = head->next->next;
            return head->val==head->next->val;
        }
        bool ans = judge(head->next, len-2, node);
        ans = ans && (head->val==node->val);
        node = node->next;
        return ans;
    }
};