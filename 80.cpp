class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int start = 0, end = 0;
        vector<int> offset(n, 0);
        int tot = 0;
        while (end<n) {
            while (end<n && nums[end]==nums[start]) offset[end++] = tot;
            if (end-start>2) 
                tot += end-start-2;
            start = end;
        }
        for (int i=0; i<n; ++i)
            nums[i-offset[i]] = nums[i];
        for (int i=0; i<tot; ++i)
            nums.pop_back();
        return n-tot;
    }
};