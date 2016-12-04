#include "head.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n==0)
            return ans;
        dfsToGenerate(ans, "", n, n);
        return ans;
    }
    void dfsToGenerate(vector<string> &ans, string currentStr, int left, int right) {
        if (left==0 && right==0) {
            ans.push_back(currentStr);
            return;
        }
        
        if (left>0) 
            dfsToGenerate(ans, currentStr+'(', left-1, right);
        if (right>left)
            dfsToGenerate(ans, currentStr+')', left, right-1);
    }
};
