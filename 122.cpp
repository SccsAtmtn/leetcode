class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0;
        int minValue = 0x80000000;
        vector<pair<int, int>> f(n+1, make_pair(minValue, minValue));
        f[0].first = 0;
        for (int i=0; i<n; ++i) {
            f[i+1].first = f[i].first;
            if (f[i].second!=minValue && f[i].second+prices[i]>f[i+1].first)
                f[i+1].first = f[i].second+prices[i];
            f[i+1].second = f[i].second;
            if (f[i].first!=minValue && f[i].first-prices[i]>f[i+1].second)
                f[i+1].second = f[i].first-prices[i];
        }
        return max(f[n].first, f[n].second);
    }
};