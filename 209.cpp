#include "head.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (s==0 || nums.size()==0)
            return 0;
        const int MAX_INT = 0x7fffffff;
        int start = 0, end = 0, sum = 0, ans = MAX_INT;
        while (end<nums.size()) {
            while (end<nums.size() && sum<s)
                sum += nums[end++];
            while (start<end && sum-nums[start]>=s)
                sum -= nums[start++];
            if (sum>=s) 
                ans = min(ans, end-start);
            sum -=nums[start++];
        }
        return (ans==MAX_INT)?0:ans;
    }
};
