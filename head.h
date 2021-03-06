#include <vector>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x):label(x) {}
};
