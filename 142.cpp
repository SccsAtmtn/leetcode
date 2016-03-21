class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==NULL) return NULL;
        ListNode * slow = head, * fast = head;
        for (;;) {
            slow = slow->next;
            if (fast==NULL || fast->next==NULL) return NULL;
            else fast = fast->next->next;
            if (slow==fast) break;
        }
        fast = head;
        for (;;) {
            if (slow==fast) return slow;
            slow = slow->next;
            fast = fast->next;
        }
    }
};