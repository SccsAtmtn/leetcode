class node {
public:
    int index, val, prime;
    node(int index, int val, int prime):index(index), val(val), prime(prime){}
    bool operator <(const node &b)const {
        return val>b.val;
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        ans.push_back(1);
        priority_queue<node> heap;
        heap.push(node(0, 2, 2));
        heap.push(node(0, 3, 3));
        heap.push(node(0, 5, 5));
        for (int i=1; i<n; ++i) {
            ans.push_back(heap.top().val);
            do {
                node current = heap.top();
                heap.pop();
                current.val = current.prime*ans[++current.index];
                heap.push(current);
            } while (!heap.empty() && heap.top().val==ans[i]);
        }
        return ans[n-1];
    }
};