class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m==0) return 0;
        int n = matrix[0].size();
        if (n==0) return 0;
        vector<int> none(n, 0);
        vector<vector<int>> f(m, none);
        for (int i=0; i<m; ++i)
            f[i][0] = (matrix[i][0]=='1');
        for (int j=0; j<n; ++j)
            f[0][j] = (matrix[0][j]=='1');
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j) 
                if (matrix[i][j]=='0')
                    f[i][j] = 0;
                else
                    f[i][j] = min(f[i-1][j-1], min(f[i][j-1], f[i-1][j]))+1;
        int ans = 0;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                ans = max(ans, f[i][j]);
        return ans*ans;
    }
};