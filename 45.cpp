class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n<=1) return 0;
        int current = 0, count = 0;
        while (current+nums[current]<n-1) {
            int max = 0, index = 0;
            for (int i=current+1; i<current+nums[current]+1; ++i)
                if (max<i+nums[i]) {
                    max = i+nums[i];
                    index = i;
                }
            current = index;
            ++count;
        }
        ++count;
        return count;
    }
};