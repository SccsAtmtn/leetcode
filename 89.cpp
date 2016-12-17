#include "head.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if (n==0)
            return vector<int>{0};
        unordered_set<int> inAns;
        dfsSearch(inAns, ans, 0, n);
        return ans;
    }
    void dfsSearch(unordered_set<int> &inAns, vector<int> &ans, int number, int n) {
        ans.push_back(number);
        inAns.insert(number);
        for (int i=0; i<n; ++i) {
            int temp;
            if ((number&(1<<i))==0)
                temp = number+(1<<i);
            else
                temp = number-(1<<i);
            if (inAns.find(temp)==inAns.end()) {
                dfsSearch(inAns, ans, temp, n);
                break;
            }
        }
    }   
};
