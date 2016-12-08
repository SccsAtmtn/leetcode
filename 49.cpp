#include "head.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        if (n==0)
            return ans;
        unordered_map<string, vector<string>> groups;
        for (int i=0; i<n; ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            auto it = groups.find(str);
            if (it==groups.end()) 
                groups.insert(make_pair(str, vector<string>{strs[i]}));
            else
                it->second.push_back(strs[i]);
        }
        for (auto it=groups.begin(); it!=groups.end(); ++it)
            ans.push_back(it->second);
        return ans;
    }
};
