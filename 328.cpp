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
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode * current = head, * next1, * head1;
        next1 = current->next;
        if (next1==NULL) return head;
        head1 = next1;
        while (current!=NULL) {
            ListNode * next2 = next1->next;
            if (next2==NULL) break;
            current->next = next2;
            next1->next = next2->next;
            current = next2;
            next1 = current->next;
            if (next1==NULL) break;
        }
        current->next = head1;
        return head;
    }
};