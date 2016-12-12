#include "head.h"

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m==0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n==0)
            return 0;
        vector<vector<int>> pathCount(m, vector<int>(n, 0));
        pathCount[0][0] = (obstacleGrid[0][0]==0);
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (!(i==0 && j==0))
                    if (i==0)
                        pathCount[i][j] = (obstacleGrid[i][j]==1)?0:pathCount[i][j-1];
                    else if (j==0)
                        pathCount[i][j] = (obstacleGrid[i][j]==1)?0:pathCount[i-1][j];
                    else 
                        pathCount[i][j] = (obstacleGrid[i][j]==1)?0:pathCount[i-1][j]+pathCount[i][j-1];
        return pathCount[m-1][n-1];
    }
};
