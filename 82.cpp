#include "head.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        ListNode *start = head, *previous = nullptr, *end = nullptr;
        while (start) {
            end = start->next;
            int cnt = 1;
            while (end && end->val==start->val) {
                end = end->next;
                ++cnt;
            }
            if (cnt>1) {
                if (previous)
                    previous->next = end;
                else 
                    head = end;
            }
            else 
                previous = start;
            start = end;
        }
        return head;
    }            
};
