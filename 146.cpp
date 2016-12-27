#include "head.h"

struct BiDirListNode {
    int key, value;
    BiDirListNode *next, *prev;
    BiDirListNode(int key, int value):key(key), value(value) {
        next = prev = nullptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity):capacity(capacity) {
        size = 0;
        head = tail = nullptr;
    }

    int get(int key) {
        BiDirListNode *currentNode = head;
        while (currentNode && currentNode->key!=key) 
            currentNode = currentNode->next;
        if (!currentNode)
            return -1;
        BiDirListNode *prevNode = currentNode->prev, *nextNode = currentNode->next;
        if (nextNode) {
            if (prevNode) {
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
            }
            else {
                head = nextNode;
                head->prev = nullptr;
            }
            tail->next = currentNode;
            currentNode->prev = tail;
            currentNode->next = nullptr;
            tail = currentNode;
        }
        return tail->value;
    }

    void set(int key, int value) {
        BiDirListNode *currentNode = head;
        while (currentNode && currentNode->key!=key) 
            currentNode = currentNode->next;
        if (!currentNode) {
            if (size==capacity) {
                BiDirListNode *temp = head;
                head = head->next;
                if (head)
                    head->prev = nullptr;
                delete temp;
                if (head) {
                    tail->next = new BiDirListNode(key, value);
                    temp = tail;
                    tail = tail->next;
                    tail->prev = temp;
                }
                else {
                    head = tail = new BiDirListNode(key, value);
                }
            }
            else {
                if (tail) {
                    BiDirListNode *temp = tail;
                    tail->next = new BiDirListNode(key, value);
                    tail = tail->next;
                    tail->prev = temp;
                }
                else {
                    head = tail = new BiDirListNode(key, value);
                }
                ++size;
            }
        }
        else {
            BiDirListNode *prevNode = currentNode->prev, *nextNode = currentNode->next;
            if (nextNode) {
                if (prevNode) {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                }
                else {
                    head = nextNode;
                    nextNode->prev = nullptr;
                }
                tail->next = currentNode;
                currentNode->prev = tail;
                currentNode->next = nullptr;
                tail = currentNode;
                tail->value = value;
            }
            else 
                currentNode->value = value;
        }
    }
private:
    BiDirListNode *head, *tail;
    int size, capacity;
};
