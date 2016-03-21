class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<pair<string, string> > pat;
        str = str+" ";
        int indexStr = 0;
        int tot = 0;
        while ((indexStr<str.length()) && (indexStr=str.find(" ", indexStr))!=string::npos) {
            ++tot;
            ++indexStr;
        }
        indexStr = 0;
        if (tot!=pattern.length()) return false;
        for (int i = 0; i<pattern.length(); ++i) {
            string sub = pattern.substr(i, 1);
            int ind = str.find(" ", indexStr);
            string subs = str.substr(indexStr, ind-indexStr);
            indexStr = ind+1;
            int index = -1;
            for (int j = 0; j<pat.size(); ++j) {
                if (pat[j].first == sub || pat[j].second == subs) {
                    index = j;
                    break;
                }
            }
            if (index!=-1) {
                if (pat[index].first!=sub || pat[index].second!=subs) return false;
            }
            else {
                pat.push_back(make_pair(sub, subs));
            }
        }
        return true;
    }
};