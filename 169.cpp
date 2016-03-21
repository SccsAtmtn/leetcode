class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> count(32, 0);
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            int t = nums[i];
            for (int j=0; j<32; ++j)
                count[j] += ((t & (1<<j))!=0);
        }
        int ans = 0;
        for (int i=0; i<32; ++i)
            if (count[i]>=(n/2+n%2))
                ans |= 1<<i;
        return ans;
    }
};