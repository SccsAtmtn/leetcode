#include "head.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        if (x==0)
            return true;
        int tempX = x, len = 0;
        while (tempX>0) {
            ++len;
            tempX /= 10;
        }
        int right = 0;
        int left = x;
        for (int i=0; i<len/2; ++i) {
            right = right*10+left%10;
            left /= 10;
        } 
        if (len%2==1)
            left /= 10;
        return (left==right);
    }
};
