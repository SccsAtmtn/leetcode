#include "head.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x==0)
            return 0;
        int left = 1, right = x;
        int ans = -1;
        while (left<=right) {
            long long mid = left+(right-left)/2;
            if (mid*mid<=static_cast<long long>(x)) {
                ans = mid;
                left = mid+1;
            }
            else
                right = mid-1;
        }
        return ans;
    }
};
