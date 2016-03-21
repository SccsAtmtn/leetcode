class Solution {
public:
    vector<string> temp;
    vector<vector<string>> ans;
    vector<vector<bool>> f;
    vector<vector<string>> partition(string s) {
        int len = s.length();
        if (len==0) return ans;
        vector<bool> one(len, false);
        for (int i=0; i<=len; ++i)
            f.push_back(one);
        for (int i=0; i<len; ++i)
            f[1][i] = true;
        for (int i=0; i<len-1; ++i)
            f[2][i] = (s[i]==s[i+1]);
        for (int i=3; i<=len; ++i)
            for (int j=0; j<len-i+1; ++j) 
                f[i][j] = f[i-2][j+1] && (s[j]==s[j+i-1]);
        dfs(s, 0);
        return ans;
    }
    void dfs(string & s, int index) {
        int len = s.length();
        if (index==len) {
            ans.push_back(temp);
            return;
        }
        for (int i=index; i<len; ++i) 
            if (f[i-index+1][index]) {
                temp.push_back(s.substr(index, i-index+1));
                dfs(s, i+1);
                temp.pop_back();
            }
    }
};