class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string str = "#";
        for (int i=0; i<n; ++i)
            str = str+s[i]+"#";
        vector<int> P(2*n+1, 1);
        int id = 0, mx = 0;
        for (int i=1; i<2*n+1; ++i) {
            if (i<mx) {
                int j = 2*id-i;
                if (P[j]<mx-i+1)
                    P[i] = P[j];
                else
                    if (P[j]==mx-i+1) {
                        int right = mx;
                        while (right+1<=2*i && right+1<2*n+1 && str[right+1]==str[2*i-right-1]) ++right;
                        P[i] = right-i+1;
                        if (right>mx) {
                            mx = right;
                            id = i;
                        }
                    }
                    else P[i] = mx-i+1;
            }
            else {
                int right = i;
                while (right+1<=2*i && right+1<2*n+1 && str[right+1]==str[2*i-right-1]) ++right;
                P[i] = right-i+1;
                if (right>mx) {
                    mx = right;
                    id = i;
                }
            }
        }
        int index = 0;
        for (int i=1; i<2*n+1; ++i)
            if (P[i]==i+1) index = i;
        string ans = s;
        int start;
        if (index%2==0) start = index;
        else start = index;
        for (;start<n; ++start)
            ans = s[start]+ans;
        return ans;
    }
};