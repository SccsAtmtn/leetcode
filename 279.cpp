class Solution {
public:
    int ans = round(1e9);
    int numSquares(int n) {
        dfs(n, floor(sqrt(n)), 0);
        return ans;
    }
    void dfs(int n, int upper, int t) {
        if (n==0) {
            ans = t;
            return;
        }
        if (t>=ans) return;
        for (int i=upper; i>0; --i) 
            if (n>=i*i) dfs(n-i*i, i, t+1);
    }
};