class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.length(), tLen = t.length();
        if (sLen<tLen) return 0;
        vector<int> one(tLen+1, 0);
        vector<vector<int>> f(sLen+1, one);
        for (int i=0; i<=sLen; ++i) {
            f[i][0] = 1;
            for (int j=1; j<=min(i, tLen); ++j) 
                f[i][j] = f[i-1][j]+(s[i-1]==t[j-1])*f[i-1][j-1];
        }
        return f[sLen][tLen];
    }
};