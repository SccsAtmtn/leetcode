class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len==0) return 0;
        stack<pair<char, int>> stk;
        int ans = 0;
        for (int i=0; i<len; ++i)
            if (s[i]=='(')
                stk.push(make_pair('(', i));
            else 
                if (!stk.empty() && stk.top().first=='(') {
                    stk.pop();
                    if (stk.empty())
                        ans = max(ans, i+1);
                    else
                        ans = max(ans, i-stk.top().second);
                }
                else
                    stk.push(make_pair(')', i));
        return ans;
    }
};