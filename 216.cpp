#include "head.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if (k>9 || n>45)
            return ans;
        vector<int> current;
        dfs(ans, current, 1, k, n);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &current, int start, int restK, int restN) {
        if (restK==1) {
            if (restN>=start && restN<=9) {
                current.push_back(restN);
                ans.push_back(current);
                current.pop_back();
            }
            return;
        }
        
        if (restN<start)
            return;
        for (int i=start; i<=min(9, restN); ++i) {
            current.push_back(i);
            dfs(ans, current, i+1, restK-1, restN-i);
            current.pop_back();
        }
    }
};
