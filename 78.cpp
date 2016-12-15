#include "head.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n==0)
            return ans;
        vector<int> current;
        dfsSearch(ans, current, nums, 0);
        return ans;
    }
    void dfsSearch(vector<vector<int>> &ans, vector<int> &current, vector<int> &nums, int pos) {
        if (pos==nums.size()) {
            ans.push_back(current);
            return;
        }
        dfsSearch(ans, current, nums, pos+1);
        current.push_back(nums[pos]);
        dfsSearch(ans, current, nums, pos+1);
        current.pop_back();
    }
};
