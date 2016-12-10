#include "head.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int start = -1, end = -1;
        for (int i=s.length()-1; i>=0; --i)
            if (s[i]!=' ')
                if (start==-1)
                    start = i;
                else;
            else if (start!=-1 && end==-1) {
                end = i;
                break;
            }
        if (start!=-1)
            ans = start-end;
        return ans;
    }
};
