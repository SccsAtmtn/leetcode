class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        if (n==0) return "";
        vector<int> count(26, 0);
        vector<bool> inAns(26, false);
        for (int i=0; i<n; ++i) 
            ++ count[(int)s[i]-97];
        vector<char> ans;
        for (int i=0; i<n; ++i) {
            --count[(int)s[i]-97];
            if (ans.empty()) {
                ans.push_back(s[i]);
                inAns[(int)s[i]-97] = true;
                continue;
            }
            if (inAns[(int)s[i]-97]) continue;
            while (!ans.empty() && ans.back()>s[i] && count[(int)ans.back()-97]>0) {
                inAns[(int)ans.back()-97] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            inAns[(int)s[i]-97] = true;
        }
        string str("");
        for (int i=0; i<ans.size(); ++i)
            str = str+ans[i];
        return str;
    }
};