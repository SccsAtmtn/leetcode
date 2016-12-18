#include "head.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.length()==0)
            return ans;
        string ip;
        dfsSearch(ans, ip, s, 0, 0);
        return ans;
    }
    void dfsSearch(vector<string> &ans, string &ip, string s, int start, int index) {
        if (start==s.length()) {
            if (index==4)
                ans.push_back(ip);
            return;
        }
        if (index>3)
            return;
        string temp = ip;
        if (s[start]=='0') {
            if (index==0)
                ip = ip+'0';
            else 
                ip = ip+".0";
            dfsSearch(ans, ip, s, start+1, index+1);
            ip = temp;
            return;
        }
        for (int end=start+1; end<min(start+3, 1+static_cast<int>(s.length())); ++end) {
            if (index==0)
                ip = ip+s.substr(start, end-start);
            else
                ip = ip+'.'+s.substr(start, end-start);
            dfsSearch(ans, ip, s, end, index+1);
            ip = temp;
        }
        if (start+3<=s.length()) {
            string current = s.substr(start, 3);
            if (current[0]<'2' || (current[0]=='2' && current[1]<'5') || (current[0]=='2' && current[1]=='5' && current[2]<='5')) {
                if (index==0)
                    ip = ip+current;
                else
                    ip = ip+'.'+current;
                dfsSearch(ans, ip, s, start+3, index+1);
                ip = temp;
            }
        }
    }
};
