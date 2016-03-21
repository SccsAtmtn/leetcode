class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n==0) return 0;
        vector<int> maxHeight(n, INT_MAX);
        int preMax = height[0];
        maxHeight[0] = height[0];
        for (int i=1; i<n-1; ++i) {
            preMax = max(preMax, height[i]);
            maxHeight[i] = preMax;
        }
        preMax = height[n-1];
        for (int i=n-2; i>0; --i) {
            preMax = max(preMax, height[i]);
            maxHeight[i] = min(maxHeight[i], preMax);
        }
        int ans = 0;
        for (int i=1; i<n-1; ++i)
            ans += maxHeight[i]-height[i];
        return ans;
    }
};