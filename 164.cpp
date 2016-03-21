class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return 0;
        vector<pair<int, int>> slot(n, make_pair(0x7fffffff, -1));
        int minNum = 0x7fffffff, maxNum = -1;
        for (int i=0; i<n; ++i) {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
        }
        int gap = (maxNum-minNum)/n+1, ans = 0;
        for (int i=0; i<n; ++i) {
            int index = (nums[i]-minNum)/gap;
            slot[index].first = min(slot[index].first, nums[i]);
            slot[index].second = max(slot[index].second, nums[i]);
        }
        int pre = -1;
        for (int i=0; i<n; ++i) {
            int current;
            if (slot[i].first!=0x7fffffff) { 
                current = slot[i].first;
                if (pre!=-1) 
                    ans = max(ans, current-pre);
                pre = current;
            }
            if (slot[i].second!=-1) {
                current = slot[i].second;
                if (pre!=-1) 
                    ans = max(ans, current-pre);
                pre = current;
            }
        }
        return ans;
    }
};