#include "head.h"

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        const char romanOne[4] = {'I', 'X', 'C', 'M'};
        const char romanFive[3] = {'V', 'L', 'D'};
        int current = 0;
        while (num>0) {
            int digit = num%10;
            num /= 10;
            if (digit<=3)
                while (digit>0) {
                    ans = romanOne[current]+ans;
                    --digit;
                }
            else if (digit<=5) {
                ans = romanFive[current]+ans;
                if (digit==4)
                    ans = romanOne[current]+ans;
            }
            else if (digit<=8) {
                while (digit>5) {
                    ans = romanOne[current]+ans;
                    --digit;
                }
                ans = romanFive[current]+ans;
            }
            else {
                ans = romanOne[current+1]+ans;
                ans = romanOne[current]+ans;
            }
            ++current;
        }
        return ans;
    }
};
