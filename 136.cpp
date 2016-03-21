class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); ++i) {
            ans = ans xor nums[i];
        }
        return ans;
    }
};