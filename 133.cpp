#include "head.h"

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *ans = nullptr;
        if (!node)
            return ans;
        unordered_map<int, UndirectedGraphNode *> relation;
        ans = new UndirectedGraphNode(node->label);
        relation.insert(make_pair(ans->label, ans));
        queue<UndirectedGraphNode *> q, p;
        q.push(ans);
        p.push(node);
        while (!q.empty()) {
            UndirectedGraphNode *currentNode = q.front();
            UndirectedGraphNode *originalNode = p.front();
            q.pop();
            p.pop();
            for (int i=0; i<originalNode->neighbors.size(); ++i) {
                UndirectedGraphNode *candidate = originalNode->neighbors[i];
                auto iter = relation.find(candidate->label);
                if (iter==relation.end()) {
                    UndirectedGraphNode *newNode = new UndirectedGraphNode(candidate->label);
                    currentNode->neighbors.push_back(newNode);
                    relation.insert(make_pair(newNode->label, newNode));
                    q.push(newNode);
                    p.push(candidate);
                }
                else
                    currentNode->neighbors.push_back(iter->second);
            }
        }
        return ans;
    }
};
