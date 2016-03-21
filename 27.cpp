class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i=0; i<nums.size(); ++i) 
            if (nums[i]==val) {
                while (nums[nums.size()-1]==val) nums.pop_back();
                if (i==nums.size()) break;
                nums[i] = nums[nums.size()-1];
                nums.pop_back();
            }
        return nums.size();
    }
};