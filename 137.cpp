class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int zero, one, two, d1, d2, d3;
        zero = 0xffffffff, one = two = 0;
        for (int i=0; i<nums.size(); ++i) {
            d1 = zero & nums[i];
            d2 = one & nums[i];
            d3 = two & nums[i];
            zero = zero-d1+d3;
            one = one-d2+d1;
            two = two-d3+d2;
        }
        return one;
    }
};