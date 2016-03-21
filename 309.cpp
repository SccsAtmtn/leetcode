class Solution {
public:
    int inf = (int)1e9;
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0;
        vector<vector<int> > f(n, vector<int>(4, -inf));
        f[0][0] = -prices[0];
        f[0][3] = 0;
        for (int i=1; i<n; ++i) {
            f[i][0] = f[i-1][3]-prices[i];
            f[i][1] = max(f[i-1][0], f[i-1][2])+prices[i];
            f[i][2] = max(f[i-1][0], f[i-1][2]);
            f[i][3] = max(f[i-1][1], f[i-1][3]);
        }
        return max(f[n-1][1], f[n-1][3]);
    }
};