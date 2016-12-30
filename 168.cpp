#include "head.h"

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        int digits = 1, number = 26;
        while (n>number) {
            n -= number;
            ++digits;
            number *= 26;
        }
        --n;
        for (int i=0; i<digits; ++i) {
            ans = static_cast<char>((n%26)+'A')+ans;
            n /= 26;
        }
        return ans;
    }
};
