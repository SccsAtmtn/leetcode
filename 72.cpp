class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<int> one(len2+1, 0);
        vector<vector<int>> f(len1+1, one);
        for (int i=0; i<=len2; ++i)
            f[0][i] = i;
        for (int i=1; i<=len1; ++i) {
            f[i][0] = i;
            for (int j=1; j<=len2; ++j)
                f[i][j] = min(f[i-1][j-1]+(word1[i-1]!=word2[j-1]), min(f[i-1][j], f[i][j-1])+1);
        }
        return f[len1][len2];
    }
};