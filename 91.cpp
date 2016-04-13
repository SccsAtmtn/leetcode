class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n==0) return 0;
        vector<int> f(n+1, 0);
        f[0] = 1;
        for (int i=0; i<n; ++i) {
            if (s[i]!='0') 
                f[i+1] = f[i];
            if (i>0 && (s[i-1]=='1' || (s[i-1]=='2' && s[i]<'7')))
                f[i+1] += f[i-1];
        }
        return f[n];
    }
};