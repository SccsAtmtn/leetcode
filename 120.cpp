#include "head.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size();
        if (m==0)
            return 0;
        const int MAX_INT = 0x7fffffff;
        vector<int> f(m, MAX_INT), g(m, MAX_INT);
        f[0] = triangle[0][0];
        for (int i=1; i<m; ++i) {
            for (int j=0; j<=i; ++j) {
                if (j==0)
                    g[j] = f[j]+triangle[i][j];
                else
                    g[j] = min(f[j], f[j-1])+triangle[i][j];
            }
            f.swap(g);
        }
        int ans = MAX_INT;
        for (int i=0; i<m; ++i)
            ans = min(ans, f[i]);
        return ans;
    }
};
