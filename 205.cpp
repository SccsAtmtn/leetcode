class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapping1;
        map<char, char> mapping2;
        int n = s.length();
        if (n==0) return true;
        for (int i=0; i<n; ++i) {
            map<char, char>::iterator st = mapping1.find(s[i]);
            map<char, char>::iterator tt = mapping2.find(t[i]);
            if (st==mapping1.end() && tt==mapping2.end()) {
                mapping1.insert(make_pair(s[i], t[i]));
                mapping2.insert(make_pair(t[i], s[i]));
            }
            else
                if (st==mapping1.end() || tt==mapping2.end()) return false;
                else
                    if (st->second!=t[i] || tt->second!=s[i]) return false;
        }
        return true;
    }
};