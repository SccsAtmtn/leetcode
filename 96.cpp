#include "head.h"

class Solution {
public:
    int numTrees(int n) {
        if (n==0)
            return 0;
        vector<int> f(n+1, 0);
        f[0] = f[1] = 1;
        for (int i=2; i<=n; ++i) {
            for (int j=0; j<i/2; ++j)
                f[i] += f[j]*f[i-(j+1)]*2;
            if (i%2==1)
                f[i] += f[i/2]*f[i/2];
        }
        return f[n];
    }
};
