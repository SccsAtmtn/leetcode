class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0, delta = INT_MAX;
        for (int i=0; i<n-2; ++i) 
            if (i==0 || nums[i]!=nums[i-1]) {
                int curTar = target-nums[i];
                int start = i+1, end = n-1;
                while (start<end) {
                    while (start<end && nums[start]+nums[end]<curTar) {
                        if (delta>curTar-(nums[start]+nums[end])) {
                            ans = nums[start]+nums[end]+nums[i];
                            delta = target-ans;
                        }
                        ++start;
                    }
                    while (start<end && nums[start]+nums[end]>curTar) {
                        if (delta>nums[start]+nums[end]-curTar) {
                            ans = nums[start]+nums[end]+nums[i];
                            delta = ans-target;
                        }
                        --end;
                    }
                    if (start>=end) break;
                    if (nums[start]+nums[end]==curTar) {
                        return target;
                    }
                }
            }
        return ans;
    }
};