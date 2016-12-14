#include "head.h"

class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        if (path.length()==0)
            return ans;
        stack<string> directory;
        int start = 0, end = 0;
        while (start<path.length()) {
            end = start+1;
            while (end<path.length() && path[end]!='/')
                ++end;
            string currentDir = path.substr(start, end-start);
            start = end;
            if (currentDir=="/")
                continue;
            else if (currentDir=="/.")
                continue;
            else if (currentDir=="/..") {
                if (!directory.empty())
                    directory.pop();
            }
            else
                directory.push(currentDir);
        }
        while (!directory.empty()) {
            ans = directory.top()+ans;
            directory.pop();
        }
        if (ans=="")
            ans = "/";
        return ans;
    }
};
