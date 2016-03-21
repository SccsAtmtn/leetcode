class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0, sum = 0, i = 0, num = nums.size();
        while (sum<n) {
            if (i<num && nums[i]<=sum+1) {
                sum += nums[i];
                ++ i;
            }
            else {
                ++ patch;
                if (sum>(INT_MAX-1)/2)
                    sum = INT_MAX;
                else
                    sum = sum*2+1;
            }
        }
        return patch;
    }
};