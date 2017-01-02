#include "head.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        vector<int> mBits, nBits;
        while (m>0) {
            mBits.push_back(m%2);
            m /= 2;
        }   
        while (n>0) {
            nBits.push_back(n%2);
            n /= 2;
        }
        if (nBits.size()>mBits.size())
            return 0;
        int index = mBits.size();
        for (int i=mBits.size()-1; i>=0; --i)
            if (mBits[i]!=nBits[i]) {
                index = i;
                break;
            }
        if (index!=mBits.size()) {
            for (int i=index; i>=0; --i)
                mBits[i] = 0;
        }
        int ans = 0;
        for (int i=mBits.size()-1; i>=0; --i) 
            ans = ans*2+mBits[i];
        return ans;
    }
};
