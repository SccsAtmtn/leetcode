class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        vector<pair<int, int> > f(n, make_pair(0, 0));
        f[0].first = nums[0];
        for (int i=1; i<n; ++i) {
            f[i].first = f[i-1].second+nums[i];
            f[i].second = max(f[i-1].first, f[i-1].second);
        }
        return max(f[n-1].first, f[n-1].second);
    }
};