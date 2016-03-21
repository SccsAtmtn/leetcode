class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return;
        int start = 0, end = n-1, pre = -1;
        while (start<end) {
            while (start<end && nums[start]==0) pre = start++;
            while (start<end && nums[end]!=0) --end;
            if (start==end) break;
            swap(nums[start], nums[end]);
            pre = start++;
            --end;
        }
        start = pre+1;
        while (start<n && nums[start]==0) ++start;
        end = n-1;
        while (start<end) {
            while (start<end && nums[start]==1) ++start;
            while (start<end && nums[end]==2) --end;
            if (start==end) break;
            swap(nums[start], nums[end]);
            ++start; 
            --end;
        }
    }
};