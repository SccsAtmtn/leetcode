class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n==0) return 0;
        vector<pair<int, int>> stack;
        vector<int> left(n, -1), right(n, -1);
        for (int i=0; i<n; ++i) {
            while (!stack.empty() && stack.back().first>=heights[i]) {
                stack.pop_back();
            }
            if (stack.empty()) 
                left[i] = 0;
            else
                left[i] = stack.back().second+1;
            stack.push_back(make_pair(heights[i], i));
        }
        stack.clear();
        for (int i=n-1; i>=0; --i) {
            while (!stack.empty() && stack.back().first>=heights[i]) {
                stack.pop_back();
            }
            if (stack.empty())
                right[i] = n-1;
            else
                right[i] = stack.back().second-1;
            stack.push_back(make_pair(heights[i], i));
        }
        int ans = 0;
        for (int i=0; i<n; ++i)
            ans = max(ans, (right[i]-left[i]+1)*heights[i]);
        return ans;
    }
};