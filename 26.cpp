class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int t = 0;
        for (int i=0; i<nums.size();) {
            nums[t++] = nums[i];
            int j = i+1;
            while (j<nums.size() && nums[i]==nums[j]) ++j;
            if (j==nums.size()) break;
            i = j;
        }
        while (nums.size()>t) nums.pop_back();
        return t;
    }
};