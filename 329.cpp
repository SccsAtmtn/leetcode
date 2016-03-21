class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        bool flag = true;
        int m = matrix.size();
        if (m==0) return 0;
        int n = matrix[0].size();
        if (n==0) return 0;
        vector<int> init(n, 1);
        vector<vector<int>> f(m, init);
        while (flag) {
            flag = false;
            for (int i=0; i<m; ++i) 
                for (int j=0; j<n; ++j) {
                    if (i!=0 && matrix[i][j]>matrix[i-1][j] && f[i][j]<f[i-1][j]+1) {
                        f[i][j] = f[i-1][j]+1;
                        flag = true;
                    }
                    if (j!=0 && matrix[i][j]>matrix[i][j-1] && f[i][j]<f[i][j-1]+1) {
                        f[i][j] = f[i][j-1]+1;
                        flag = true;
                    }
                    if (i!=m-1 && matrix[i][j]>matrix[i+1][j] && f[i][j]<f[i+1][j]+1) {
                        f[i][j] = f[i+1][j]+1;
                        flag = true;
                    }
                    if (j!=n-1 && matrix[i][j]>matrix[i][j+1] && f[i][j]<f[i][j+1]+1) {
                        f[i][j] = f[i][j+1]+1;
                        flag = true;
                    }
                }
        }
        int ans = 1;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                ans = max(ans, f[i][j]);
        return ans;
    }
};