class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> num;
        for (int i=0; i<nums.size(); ++i)
            num.insert(nums[i]);
        return num.size()<nums.size();
    }
};