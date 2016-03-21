class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head, * fast = head;
        while (slow!=NULL && fast!=NULL) {
            slow = slow->next;
            if (fast->next!=NULL) fast = fast->next->next;
            else return false;
            if (slow==fast) return true;
        }
        return false;
    }
};