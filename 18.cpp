#include "head.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size()==0)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i=3; i<nums.size(); ++i) {
            vector<vector<int>> triplet = threeSum(nums, i, target-nums[i]);
            for (int j=0; j<triplet.size(); ++j) {
                triplet[j].push_back(nums[i]);
                if (!haveExisted(triplet[j], ans))
                    ans.push_back(triplet[j]);
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums, int end, int target) {
        vector<vector<int>> ans;
        for (int i=2; i<end; ++i) {
            vector<vector<int>> pairs = twoSum(nums, i, target-nums[i]);
            for (int j=0; j<pairs.size(); ++j) {
                pairs[j].push_back(nums[i]);
                if (!haveExisted(pairs[j], ans))
                    ans.push_back(pairs[j]);
            }
        }
        return ans;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int end, int target) {
        vector<vector<int>> ans;
        int left = 0, right = end-1;
        while (left<right) {
            while (left<right && nums[left]+nums[right]<target)
                ++left; 
            while (left<right && nums[left]+nums[right]>target)
                --right;
            if (left<right && nums[left]+nums[right]==target) {
                vector<int> temp{nums[left], nums[right]};
                if (!haveExisted(temp, ans))
                    ans.push_back(temp);
                ++left;
                --right;
            }
        }
        return ans;
    }
    bool haveExisted(vector<int>& candidate, vector<vector<int>>& ans) {
        for (int i=0; i<ans.size(); ++i) {
            bool isEqual = true;
            for (int j=0; j<candidate.size(); ++j)
                if (candidate[j]!=ans[i][j]) {
                    isEqual = false;
                    break;
                }
            if (isEqual)
                return true;
        }
        return false;
    }
};
