#include "head.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length()==0)
            return ans;
        const vector<vector<char>> mapping = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<int> currentCharCnt(digits.length(), 0);
        while (true) {
            string currentStr;
            for (int i=0; i<digits.size(); ++i)
                currentStr = currentStr+mapping[digits[i]-'0'][currentCharCnt[i]];
            ans.push_back(currentStr);
            int currentDigit = digits.length()-1;
            while (currentDigit>=0 && currentCharCnt[currentDigit]==mapping[digits[currentDigit]-'0'].size()-1) {
                currentCharCnt[currentDigit] = 0;
                --currentDigit;
            }
            if (currentDigit>=0)
                ++currentCharCnt[currentDigit];
            else 
                break;
        } 
        return ans;
    }
};
