class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length(), ans = 0;
        if (n==0) return ans;
        for (int i=0; i<n; ++i) 
            ans = ans*26+(int)s[i]-64;
        return ans;
    }
};