#include "head.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> leftParenthese;
        for (int i=0; i<s.length(); ++i)
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') 
                leftParenthese.push(s[i]);
            else if (s[i]==')' || s[i]==']' || s[i]=='}') {
                if (leftParenthese.empty())
                    return false;
                if (s[i]==')')
                    if (leftParenthese.top()=='(')
                        leftParenthese.pop();
                    else
                        return false;
                else if (s[i]==']')
                    if (leftParenthese.top()=='[')
                        leftParenthese.pop();
                    else
                        return false;
                else if (s[i]=='}')
                    if (leftParenthese.top()=='{')
                        leftParenthese.pop();
                    else
                        return false;
            }
        return leftParenthese.empty();
    }
};
