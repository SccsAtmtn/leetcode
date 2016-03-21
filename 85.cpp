class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m==0) return 0;
        int n = matrix[0].size();
        if (n==0) return 0;
        vector<int> one(n, 0);
        vector<vector<int>> height(m, one);
        for (int i=0; i<n; ++i)
            height[0][i] = (matrix[0][i]=='1');
        for (int i=1; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (matrix[i][j]=='0') height[i][j] = 0;
                else height[i][j] = height[i-1][j]+1;
        int ans = 0;
        for (int i=0; i<m; ++i)
            ans = max(ans, largestRec(height[i]));
        return ans;
    }
    int largestRec(vector<int> height) {
        int n = height.size();
        vector<int> left(n, -1), right(n, -1);
        vector<pair<int, int>> stack;
        for (int i=0; i<n; ++i) {
            while (!stack.empty() && stack.back().first>=height[i]) 
                stack.pop_back();
            if (stack.empty())
                left[i] = 0;
            else
                left[i] = stack.back().second+1;
            stack.push_back(make_pair(height[i], i));
        }
        stack.clear();
        for (int i=n-1; i>=0; --i) {
            while (!stack.empty() && stack.back().first>=height[i])
                stack.pop_back();
            if (stack.empty())
                right[i] = n-1;
            else
                right[i] = stack.back().second-1;
            stack.push_back(make_pair(height[i], i));
        }
        int ans = 0;
        for (int i=0; i<n; ++i)
            ans = max(ans, (right[i]-left[i]+1)*height[i]);
        return ans;
    }
};