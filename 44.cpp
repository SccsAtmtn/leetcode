#include "head.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length(), plen = p.length();
        // f[i][j] donates whether s[0..i-1] can match p[0..j-1]
        // preS[j] donates whether there is a k equal or less than the current i that f[k][j] is true
        // preP[j] donates whether there is a k equal or less than j that for the current i, f[i-1][k] is true
        bool *f[slen+1], preS[plen+1], preP[plen+1];
        for (int i=0; i<=slen; ++i) {
            f[i] = new bool[plen+1];
            for (int j=0; j<=plen; ++j)
                f[i][j] = false;
        }
        f[0][0] = true;
        preS[0] = preP[0] = true;
        for (int i=0; i<=slen; ++i) {
            for (int j=0; j<=plen; ++j)
                if (!(i==0 && j==0)) {
                    if (i==0) {
                        if (p[j-1]=='*')
                            f[i][j] = f[i][j-1];
                        else
                            f[i][j] = false;
                    }
                    else if (j==0) {
                        if (s[i-1]=='*')
                            f[i][j] = f[i-1][j];
                        else
                            f[i][j] = false;
                    }
                    else {
                        if (s[i-1]=='*')
                            f[i][j] = preP[j];
                        else if (p[j-1]=='*')
                            f[i][j] = preS[j-1];
                        else if (s[i-1]=='?' || p[j-1]=='?' || s[i-1]==p[j-1])
                            f[i][j] = f[i-1][j-1];
                        else
                            f[i][j] = false;
                    }
                    preS[j] = (i!=0 && preS[j]) || f[i][j];
                    preP[j] = (j!=0 && preP[j-1]) || f[i][j];
                }
            }
        return f[slen][plen];
    }
};
