#include "head.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1)
            return s; 
        int offset = 0, step = numRows*2-2;
        string ans;
        int slen = s.length();
        while (offset<numRows) {
            int current = 0;
            while (current-offset<slen) {
                if (offset!=0 && offset!=numRows-1 && current-offset>=0)
                    ans += s[current-offset];
                if (current+offset<slen)
                    ans += s[current+offset];
                current += step;
            }
            ++offset;
        }
        return ans;
    }
};
