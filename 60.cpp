#include "head.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        set<int> numbers;
        for (int i=1; i<=n; ++i)
            numbers.insert(i);
        int currentPos = n-1, power = 1;
        for (int i=1; i<=n-1; ++i)
            power *= i;
        int left = k;
        while (currentPos>=0) {
            int currentRank = (left-1)/power;
            auto ptr = numbers.begin();
            for (int i=0; i<currentRank; ++i)
                ++ptr;
            ans = ans+static_cast<char>((*ptr)+'0');
            numbers.erase(ptr);
            left -= power*currentRank;
            if (currentPos!=0)
                power /= currentPos;
            --currentPos;
        }
        return ans;
    }
};
