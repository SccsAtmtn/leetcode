class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return true;
        int current = 0, max = nums[0];
        while (max<n-1) {
            int temp = max, index = -1;
            for (int i=current+1; i<=temp; ++i) 
                if (i+nums[i]>max) {
                    max = i+nums[i];
                    index = i;
                }
            if (index==-1) return false;
            current = index;
        }
        return true;
    }
};