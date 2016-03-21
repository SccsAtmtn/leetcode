class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k==0 || n==0) return 0;
        if (k>n/2) {
            int ans = 0;
            for (int i=1; i<n; ++i)
                ans += max(prices[i]-prices[i-1], 0);
            return ans;
        }
        int minValue = 0x80000000;
        vector<int> one(2, minValue);
        vector<vector<int>> two(2, one);
        vector<vector<vector<int>>> f(n+1, two);
        for (int i=0; i<=n; ++i)
            f[i][0][0] = 0;
        int current = 0;
        int ans = 0;
        for (int j=1; j<=k; ++j) {
            current = 1-current;
            for (int i=1; i<=n; ++i) {
                f[i][current][0] = f[i-1][current][0];
                if (f[i-1][current][1]!=minValue && f[i-1][current][1]+prices[i-1]>f[i][current][0])
                    f[i][current][0] = f[i-1][current][1]+prices[i-1];
                f[i][current][1] = f[i-1][current][1];
                if (f[i-1][1-current][0]!=minValue && f[i-1][1-current][0]-prices[i-1]>f[i][current][1])
                    f[i][current][1] = f[i-1][1-current][0]-prices[i-1];
            }
            ans = max(ans, max(f[n][current][0], f[n][current][1]));
        }
        return ans;
    }
};