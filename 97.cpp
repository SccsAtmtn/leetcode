class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len3!=len1+len2) return false;
        if (len1==0) return (s2==s3);
        if (len2==0) return (s1==s3);
        vector<bool> one(len1+1, false);
        vector<vector<bool>> f(len3+1, one);
        f[0][0] = true;
        for (int i=1; i<=len3; ++i) {
            f[i][0] = (s3.substr(0, i)==s2.substr(0, i));
            for (int j=1; j<=min(i, len1); ++j) 
                f[i][j] = (f[i-1][j] && s2[i-j-1]==s3[i-1]) || (f[i-1][j-1] && s1[j-1]==s3[i-1]);
        }
        return f[len3][len1];
    }
};