#include "head.h"

class Solution {
public:
    string countAndSay(int n) {
        string ans("1");
        --n;
        while (n>0) {
            string temp;
            char currentChar = ans[0];
            int currentPos = 1, cnt = 1;
            while (currentPos<ans.length()) {
                if (ans[currentPos]==currentChar)
                    ++cnt;
                else {
                    temp = temp+intToStr(cnt)+currentChar;
                    currentChar = ans[currentPos];
                    cnt = 1;
                }
                ++currentPos;
            }
            temp = temp+intToStr(cnt)+currentChar;
            ans = temp;
            --n;
        }
        return ans;
    }
    string intToStr(int n) {
        string ans;
        while (n>0) {
            ans = static_cast<char>(n%10+48)+ans;
            n /= 10;
        }
        return ans;
    }
};
