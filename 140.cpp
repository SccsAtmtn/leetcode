class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int lenS = s.length();
        vector<string> one;
        if (lenS==0) return one;
        vector<vector<string>> f(lenS, one);
        vector<bool> flag(lenS, false);
        int maxLen = 0;
        for (auto ptr = wordDict.begin(); ptr!=wordDict.end(); ++ptr) {
            int len = (*ptr).length();
            maxLen = max(maxLen, len);
        }
        for (int i=lenS-1; i>=0; --i) {
            string str = s.substr(i, lenS-i);
            if (wordDict.find(str)!=wordDict.end()) {
                flag[i] = true;
                continue;
            }
            for (int j=i+1; j<min(i+maxLen+1, lenS); ++j)
                if (flag[j]) {
                    string str1 = s.substr(i, j-i);
                    if (wordDict.find(str1)!=wordDict.end()) {
                        flag[i] = true;
                        break;
                    }
                }
        }
        if (!flag[0]) return one;
        for (int i=lenS-1; i>=0; --i) {
            string str = s.substr(i, lenS-i);
            if (wordDict.find(str)!=wordDict.end())
                f[i].push_back(str);
            for (int j=i+1; j<min(i+maxLen+1, lenS); ++j) 
                if (f[j].size()>0) {
                    string str1 = s.substr(i, j-i);
                    if (wordDict.find(str1)!=wordDict.end())
                        for (int k=0; k<f[j].size(); ++k) 
                            f[i].push_back(str1+" "+f[j][k]);
                }
        }
        return f[0];
    }
};