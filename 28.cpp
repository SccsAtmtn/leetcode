#include "head.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()==0)
            return 0;
        for (int i=0; i<=static_cast<int>(haystack.size())-static_cast<int>(needle.size()); ++i)
            for (int j=0; j<needle.size(); ++j)
                if (haystack[i+j]!=needle[j])
                    break;
                else if (j==needle.size()-1)
                    return i;
        return -1;
    }
};
