class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0;
        int minValue = 0x80000000;
        vector<int> one(4, minValue);
        vector<vector<int>> f(n+1, one);
        for (int i=1; i<=n; ++i) {
            f[i][0] = f[i-1][0];
            if (f[i-1][1]!=minValue && f[i-1][1]+prices[i-1]>f[i][0]) 
                f[i][0] = f[i-1][1]+prices[i-1];
            f[i][1] = max(-prices[i-1], f[i-1][1]);
            f[i][2] = f[i-1][2];
            if (f[i-1][3]!=minValue && f[i-1][3]+prices[i-1]>f[i][2])
                f[i][2] = f[i-1][3]+prices[i-1];
            f[i][3] = f[i-1][3];
            if (f[i-1][0]!=minValue && f[i-1][0]-prices[i-1]>f[i][3])
                f[i][3] = f[i-1][0]-prices[i-1];
        }
        return max(0, max(max(f[n][0], f[n][1]), max(f[n][2], f[n][3])));
    }
};