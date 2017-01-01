#include "head.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        for (int i=0; i<=static_cast<int>(s.length())-10; ++i) {
            string temp = s.substr(i, 10);
            auto iter = cnt.find(temp);
            if (iter==cnt.end()) 
                cnt.insert(make_pair(temp, 1));
            else
                ++(iter->second);
        }
        for (auto iter = cnt.begin(); iter!=cnt.end(); ++iter)
            if (iter->second>=2)
                ans.push_back(iter->first);
        return ans;
    }
};
