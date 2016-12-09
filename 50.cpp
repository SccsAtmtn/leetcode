#include "head.h"

class Solution{
public:
    double myPow(double x, int n) {
        if (n==0)
            return 1;
        bool negative = (n<0);
        long long nn = abs(static_cast<long long>(n));
        double power = 1;
        while (nn>0) {
            long long multi = 1;
            double bina = x;
            while (multi*2<=nn) {
                multi *= 2;
                bina *= bina;
            }
            nn -= multi;
            power *= bina;
        }
        return (negative)?1/power:power;
    }
};
