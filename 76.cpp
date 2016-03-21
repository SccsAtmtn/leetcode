class Solution {
public:
    string minWindow(string s, string t) {
        int lenS = s.length(), lenT = t.length();
        if (lenT==0) return "";
        vector<int> count(256, 0), inT(256, 0);
        int numberT = 0;
        for (int i=0; i<t.length(); ++i) {
            ++inT[t[i]];
            if (inT[t[i]]==1) ++numberT;
        }
        int number = 0;
        int start = 0, end = -1, ansStart = 0, ansEnd = -1, ansLen = INT_MAX;
        for (;;) {
            while (end<lenS-1 && number<numberT) {
                ++end;
                if (inT[s[end]]>0) {
                    ++count[s[end]];
                    if (count[s[end]]==inT[s[end]]) 
                        ++number;
                }
            }
            if (number<numberT) break;
            while (number==numberT) {
                if (inT[s[start]]>0) {
                    --count[s[start]];
                    if (count[s[start]]==inT[s[start]]-1) 
                        --number;
                }
                ++start;
            }
            if (ansLen>end-start+2) {
                ansLen = end-start+2;
                ansStart = start-1;
                ansEnd = end;
            }
        }
        if (ansLen==INT_MAX) return "";
        else return s.substr(ansStart, ansLen);
    }
};