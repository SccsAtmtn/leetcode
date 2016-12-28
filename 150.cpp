#include "head.h"

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size()==0)
            return 0;
        stack<int> st;
        for (int i=0; i<tokens.size(); ++i) 
            if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int c;
                if (tokens[i]=="+")
                    c = a+b;
                else if (tokens[i]=="-")
                    c = a-b;
                else if (tokens[i]=="*")
                    c = a*b;
                else if (tokens[i]=="/")
                    c = a/b;
                st.push(c);
            }
            else {
                int num = 0;
                int sign = 1;
                int start = 0;
                if (tokens[i][0]=='+')
                    start = 1;
                else if (tokens[i][0]=='-') {
                    start = 1;
                    sign = -1;
                }
                for (int j=start; j<tokens[i].size(); ++j)
                    num = num*10+static_cast<int>(tokens[i][j])-48;
                st.push(num*sign);
            }
        return st.top();
    }
};
