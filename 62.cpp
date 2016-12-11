#include "head.h"

class Solution{
public:
    int uniquePaths(int m, int n) {
        if (m==0 || n==0)
            return 0;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (i==0 || j==0)   
                    ans[i][j] = 1;
                else 
                    ans[i][j] = ans[i-1][j]+ans[i][j-1];
        return ans[m-1][n-1];
    }
};
