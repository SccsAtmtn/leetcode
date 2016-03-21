class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minimum = 0x80000000;
        int n = nums.size();
        if (n==0) return false;
        int max1 = minimum, max2 = minimum;
        for (int i=n-1; i>=0; --i) {
            if (max1==minimum || nums[i]>max1) {
                max1 = nums[i];
            }
            else if ((nums[i]<max1) && (max2==minimum || nums[i]>max2)) {
                max2 = nums[i];
            }
            else if (max2>nums[i]) return true;
        }
        return false;
    }
};