#include "head.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        if (candidates.size()==0)
            return ans;
        sort(candidates.begin(), candidates.end(), cmp);
        vector<int> currentSet;
        dfsToSolve(ans, currentSet, candidates, target, 0);
        return ans;
    }
    static bool cmp(const int &a, const int &b) {
        return (a>b);
    }
    void dfsToSolve(vector<vector<int>> &ans, vector<int> &currentSet, vector<int> &candidates, int rest, int startIndex) {
        if (rest==0) {
            if (!inAns(currentSet, ans))
                ans.push_back(currentSet);
            return;
        }
        int left = startIndex, right = candidates.size()-1;
        int firstValid = -1;
        while (left<=right) {
            int mid = (left+right)/2;
            if (candidates[mid]<=rest) {
                firstValid = mid;
                right = mid-1;
            }
            else 
                left = mid+1;
        }
        if (firstValid==-1)
            return;
        for (int i=firstValid; i<candidates.size(); ++i) {
            currentSet.push_back(candidates[i]);
            dfsToSolve(ans, currentSet, candidates, rest-candidates[i], i);
            currentSet.pop_back();
        }
    }
    bool inAns(vector<int> &currentSet, vector<vector<int>> &ans) {
        for (int i=0; i<ans.size(); ++i) 
            if (currentSet.size()==ans[i].size()) {
                int isEqual = true;
                for (int j=0; j<currentSet.size(); ++j)
                    if (currentSet[j]!=ans[i][j]) {
                        isEqual = false;
                        break;
                    }
                if (isEqual)
                    return true;
        }
        return false;
    }
};
