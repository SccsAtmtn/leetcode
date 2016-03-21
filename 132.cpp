class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n<=1) return 0;
        vector<bool> one(n, false);
        vector<vector<bool>> isPald(n+1, one);
        for (int i=0; i<n; ++i) {
            isPald[1][i] = true;
            if (i<n-1) isPald[2][i] = (s[i]==s[i+1]);
        }
        for (int i=3; i<=n; ++i) 
            for (int j=0; j<n-i+1; ++j) 
                isPald[i][j] = isPald[i-2][j+1] && (s[j]==s[j+i-1]);
        vector<int> f(n+1, INT_MAX);
        f[0] = 0;
        for (int i=1; i<=n; ++i)
            for (int j=0; j<i; ++j)
                if (isPald[i-j][j])
                    f[i] = min(f[j]+1, f[i]);
        return f[n]-1;
    }
};