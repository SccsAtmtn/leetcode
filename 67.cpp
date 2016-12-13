#include "head.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int ptrA = a.length(), ptrB = b.length();
        --ptrA;
        --ptrB;
        int c = 0;
        while (ptrA>=0 && ptrB>=0) {
            c += (a[ptrA]=='1') + (b[ptrB]=='1');
            if (c%2==1)
                ans = '1'+ans;
            else
                ans = '0'+ans;
            c /= 2;
            --ptrA, --ptrB;
        }
        while (ptrA>=0) {
            c += (a[ptrA]=='1');
            if (c%2==1)
                ans = '1'+ans;
            else
                ans = '0'+ans;
            c /= 2;
            --ptrA;
        }
        while (ptrB>=0) {
            c += (b[ptrB]=='1');
            if (c%2==1)
                ans = '1'+ans;
            else
                ans = '0'+ans;
            c /= 2;
            --ptrB;
        }
        if (c==1)
            ans = '1'+ans;
        return ans;
    }
};
