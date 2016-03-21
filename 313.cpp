class node {
public:
    int index, val, prime;
    node(int index, int val, int prime):index(index), val(val), prime(prime){}
    bool operator <(node b)const {
        return val>b.val;
    }
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans;
        ans.push_back(1);
        priority_queue<node> que;
        for (int i=0; i<primes.size(); ++i)
            que.push(node(0, primes[i], primes[i]));
        for (int i=1; i<n; ++i) {
            node current = que.top();
            ans.push_back(current.val);
            do {
                current = que.top();
                que.pop();
                current.val = current.prime*ans[++current.index];
                que.push(current);
            } while (!que.empty() && que.top().val==ans[i]);
        }
        return ans[n-1];
    }
};