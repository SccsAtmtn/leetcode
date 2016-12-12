#include "head.h"

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        if (m==0)
            return 0;
        int n = grid[0].size();
        if (n==0)
            return 0;
        const int MAX_INT = 0x7fffffff;
        vector<vector<int>> minSum(m, vector<int>(n, MAX_INT));
        minSum[0][0] = grid[0][0];
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (i!=0 || j!=0)
                    if (i==0)
                        minSum[i][j] = minSum[i][j-1]+grid[i][j];
                    else if (j==0)
                        minSum[i][j] = minSum[i-1][j]+grid[i][j];
                    else
                        minSum[i][j] = min(minSum[i-1][j], minSum[i][j-1])+grid[i][j];
        return minSum[m-1][n-1];
    }
};
