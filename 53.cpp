#include "head.h"

class Solution{
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        if (n==0)
            return 0;
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i=1; i<n; ++i)
            prefixSum[i] = prefixSum[i-1]+nums[i];
        int ans = 0x80000000, minSum = 0;
        for (int i=0; i<n; ++i) {
            if (prefixSum[i]-minSum>ans)
                ans = prefixSum[i]-minSum;
            minSum = min(minSum, prefixSum[i]);
        } 
        return ans;
    }
};
