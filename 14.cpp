#include "head.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.size()==0)
            return ans;
        int maxLen = strs[0].length();
        for (int i=1; i<strs.size(); ++i)
            maxLen = min(maxLen, static_cast<int>(strs[i].length()));
        for (int i=0; i<maxLen; ++i) {
            char currentChar = strs[0][i];
            for (int j=1; j<strs.size(); ++j)
                if (strs[j][i]!=currentChar)
                    return ans;
            ans = ans+currentChar;
        }
        return ans;
    }
};
