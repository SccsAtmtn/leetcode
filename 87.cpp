class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n!=s2.length()) return false;
        vector<bool> one(n, false);
        vector<vector<bool>> two(n, one);
        vector<vector<vector<bool>>> f(n+1, two);
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                f[1][i][j] = (s1[i]==s2[j]);
        for (int i=2; i<=n; ++i)
            for (int j=0; j<n-i+1; ++j)
                for (int k=0; k<n-i+1; ++k)
                    for (int p=1; p<i; ++p) 
                        if ((f[p][j][k] && f[i-p][j+p][k+p]) || (f[p][j][k+i-p] && f[i-p][j+p][k])) {
                            f[i][j][k] = true;
                            break;
                        }
        return f[n][0][0];
    }
};