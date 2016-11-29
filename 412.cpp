#include "head.h"

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i=1; i<=n; ++i) 
            ans.push_back(intToString(i));
        return ans;
    }
    string intToString(int n) {
        if (n%3==0 && n%5==0)
            return "FizzBuzz";
        else if (n%3==0)
            return "Fizz";
        else if (n%5==0)
            return "Buzz";
        else {
            string ans;
            while (n>0) {
                ans = string{static_cast<char>(n%10+48)}+ans;
                n /= 10;
            }
            return ans;
        }
    }
};
