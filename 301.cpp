class Solution {
public:
    set<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        int leftNum = 0, rightNum = 0;
        for (int i = 0; i<s.length(); ++i) {
            if (s[i] == '(') ++leftNum;
            else
                if (s[i] == ')') {
                    if (leftNum>0) --leftNum;
                    else ++rightNum;
                }
        }
        dfs(s, 0, leftNum, rightNum, 0, "");
        vector<string> answer;
        for (set<string>::iterator i = ans.begin(); i != ans.end(); ++i)
            answer.push_back(*i);
        return answer;
    }
    void dfs(string s, int index, int leftNum, int rightNum, int open, string str) {
        if (index == s.length() && leftNum == 0 && rightNum == 0 && open == 0) {
            ans.insert(str);
            return;
        }
        if (index == s.length()) return;
        if (s[index] == '(') {
            dfs(s, index + 1, leftNum, rightNum, open + 1, str + "(");
            if (leftNum>0) dfs(s, index + 1, leftNum - 1, rightNum, open, str);
        }
        else
            if (s[index] == ')') {
                if (open>0) dfs(s, index + 1, leftNum, rightNum, open - 1, str + ")");
                if (rightNum>0) dfs(s, index + 1, leftNum, rightNum - 1, open, str);
            }
            else dfs(s, index + 1, leftNum, rightNum, open, str + s[index]);
    }
};