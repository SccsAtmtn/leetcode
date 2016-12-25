#include "head.h"

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &wordDict) {
        if (s.length()==0)
           return true; 
        vector<bool> f(s.length()+1, false);
        f[0] = true;
        for (int i=1; i<=s.length(); ++i)
            for (auto j=wordDict.begin(); j!=wordDict.end(); ++j)
                if (i>=j->length() && f[i-j->length()]) {
                    bool isEqual = true;
                    for (int k=0; k<j->length(); ++k)
                        if ((*j)[k]!=s[i-j->length()+k]) {
                            isEqual = false;
                            break;
                        }
                    if (isEqual) {
                        f[i] = true;
                        break;
                    }
                }
        return f[s.length()];
    }
};
