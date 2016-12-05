#include "head.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor==0 || (dividend==0x80000000 && divisor==-1))
            return 0x7fffffff;

        int ans = 0;
        int sign = ((dividend<0)^(divisor<0))?-1:1;
        long long divd = labs(dividend);
        long long divs = labs(divisor);
        while (divd>=divs) {
            long long num = divs;
            long long multiple = 1;
            while (num<=divd) {
                num <<= 1;
                multiple <<= 1;
            }
            num >>= 1;
            multiple >>= 1;
            divd -= num;
            ans += static_cast<int>(multiple);
        }
        return sign*ans;
    }
};
