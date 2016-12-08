#include "head.h"

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (n==0)
            return;
        int xRange = n/2, yRange = n/2+n%2;
        for (int i=0; i<xRange; ++i)
            for (int j=0; j<yRange; ++j) {
                int value = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = value;
            }
    }
};
