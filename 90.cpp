#include "head.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> numbers;
        int start = 0;
        while (start<nums.size()) {
            int end = start+1;
            while (end<nums.size() && nums[end]==nums[start]) 
                ++end;
            numbers.push_back(make_pair(nums[start], end-start));
            start = end;
        }
        vector<vector<int>> ans;
        vector<int> subset;
        dfsSearch(subset, ans, numbers, 0);
        return ans;
    }
    void dfsSearch(vector<int> &subset, vector<vector<int>> &ans, vector<pair<int, int>> &numbers, int curPtr) {
        if (curPtr==numbers.size()) {
            ans.push_back(subset);
            return;
        }
        dfsSearch(subset, ans, numbers, curPtr+1);
        for (int i=1; i<=numbers[curPtr].second; ++i) {
            subset.push_back(numbers[curPtr].first);
            dfsSearch(subset, ans, numbers, curPtr+1);
        }
        for (int i=0; i<numbers[curPtr].second; ++i)
            subset.pop_back();
    }
};

