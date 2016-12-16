#include "head.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *first = nullptr, *firstPtr = nullptr;
        ListNode *second = nullptr, *secondPtr = nullptr;
        ListNode *current = head;
        while (current) {
            ListNode *next = current->next;
            if (current->val<x) {
                if (first) {
                    firstPtr->next = current;
                    firstPtr = current;
                }
                else {
                    first = current;
                    firstPtr = current;
                }
            }
            else {
                if (second) {
                    secondPtr->next = current;
                    secondPtr = current;
                }
                else {
                    second = current;
                    secondPtr = current;
                }
            }
            current->next = nullptr;
            current = next;
        }
        if (first) {
            firstPtr->next = second;
            head = first;
        }
        else
            head = second;
        return head;
    }
};
