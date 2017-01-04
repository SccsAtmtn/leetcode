#include "head.h"

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int currentNumber = 0;
        int currentOperator = 1;
        stack<int> sign;
        sign.push(1);
        for (int i=0; i<s.length(); ++i)
            if (s[i]==' ')
                continue;
            else if (s[i]=='(') {
                sign.push(currentOperator*sign.top());
                currentOperator = 1;
            }
            else if (s[i]==')') {
                ans += sign.top()*currentOperator*currentNumber;
                currentNumber = 0;
                sign.pop();
            }
            else if (isdigit(s[i])) 
                currentNumber = currentNumber*10+(s[i]-'0');
            else {
                ans += sign.top()*currentOperator*currentNumber;
                currentNumber = 0;
                currentOperator = (s[i]=='+')?1:-1;
            }
        ans += sign.top()*currentOperator*currentNumber;
        return ans;
    }
};
