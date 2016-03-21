class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string str = "#";
        for (int i=0; i<n; ++i) 
            str = str+s[i]+"#";
        n = n*2+1;
        vector<int> P(n, 1);
        int id = 0, mx = 0;
        for (int i=1; i<n; ++i) {
            if (i<mx) {
                int j = 2*id-i;
                if (P[j]<mx-i+1)
                    P[i] = P[j];
                else
                    if (P[j]==mx-i+1) {
                        int right = mx;
                        while (right+1<=2*i && right+1<n && str[right+1]==str[2*i-right-1]) ++right;
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
                while (right+1<=2*i && right+1<n && str[right+1]==str[2*i-right-1]) ++right;
                P[i] = right-i+1;
                if (right>mx) {
                    mx = right;
                    id = i;
                }
            }
        }
        int ansLen = 0, ind = -1;
        for (int i=1; i<n; ++i) 
            if (P[i]-1>ansLen) {
                ansLen = P[i]-1;
                ind = i;
            }
        string ans = "";
        if (str[ind]=='#') {
            int cnt = 0, ptr = ind+1;
            while (cnt<ansLen) {
                cnt += 2;
                ans = str[ptr]+ans+str[ptr];
                ptr += 2;
            }
        }
        else {
            int cnt = 1, ptr = ind;
            ans += str[ptr];
            while (cnt<ansLen) {
                cnt += 2;
                ptr += 2;
                ans = str[ptr]+ans+str[ptr];
            }
        }
        return ans;
    }
};