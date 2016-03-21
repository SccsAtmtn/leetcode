/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode * current = head;
        while (current) {
            RandomListNode * newNode = new RandomListNode(current->label);
            newNode->next = current->next;
            newNode->random = current->random;
            current->next = newNode;
            current = newNode->next;
        }
        current = head;
        while (current) {
            if (current->next->random) current->next->random = current->random->next;
            current = current->next->next;
        }
        RandomListNode * ans = head->next;
        current = head;
        while (current) {
            if (current->next->next) {
                RandomListNode * next = current->next->next;
                current->next->next = next->next;
                current->next = next;
            }
            else current->next = NULL;
            current = current->next;
        }
        return ans;
    }
};