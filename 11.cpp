class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n==0) return 0;
        int start = 0, end = n-1;
        int ans = (n-1)*min(height[0], height[n-1]);
        while (start<end) {
            if (height[start]>height[end]) --end;
            else ++start;
            ans = max(ans, (end-start)*min(height[start], height[end]));
        }
        return ans;
    }
};