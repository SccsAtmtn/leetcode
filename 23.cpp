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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ans = NULL, * cur = NULL;
        int n = lists.size();
        if (n==0) return ans;
        multimap<int, int> tree; 
        vector<ListNode *> current(n, new ListNode(0));
        for (int i=0; i<n; ++i)
            current[i] = lists[i];
        for (int i=0; i<n; ++i)
            if (current[i])
                tree.insert(make_pair(current[i]->val, i));
        while (tree.size()>0) {
            pair<int, int> p = *tree.begin();
            tree.erase(tree.begin());
            ListNode * newNode = new ListNode(current[p.second]->val);
            if (!ans) 
                ans = cur = newNode;
            else {
                cur->next = newNode;
                cur = cur->next;
            }
            current[p.second] = current[p.second]->next;
            if (current[p.second])
                tree.insert(make_pair(current[p.second]->val, p.second));
        }
        return ans;
    }
};