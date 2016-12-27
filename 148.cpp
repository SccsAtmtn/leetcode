#include "head.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *currentNode = head;
        int len = 0;
        while (currentNode) {
            ++len;
            currentNode = currentNode->next;
        }
        if (len<=1)
            return head;
        int cnt = 0;
        currentNode = head;
        ListNode *previousNode = nullptr;
        while (cnt<len/2) {
            ++cnt;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        ListNode *first = head, *second = currentNode;
        previousNode->next = nullptr;
        
        first = sortList(first);
        second = sortList(second);
        
        head = currentNode = nullptr;
        while (first && second) {
            if (first->val<=second->val) {
                if (!head) 
                    head = currentNode = first;
                else {
                    currentNode->next = first;
                    currentNode = currentNode->next;
                }
                first = first->next;
                currentNode->next = nullptr;
            }
            else {
                if (!head)
                    head = currentNode = second;
                else {
                    currentNode->next = second;
                    currentNode = currentNode->next;
                }
                second = second->next;
                currentNode->next = nullptr;
            }
        }
        if (first)
            currentNode->next = first;
        if (second)
            currentNode->next = second;
        return head;
    }       
};
