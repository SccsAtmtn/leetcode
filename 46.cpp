class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n==0) return ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while (true) {
            int index = n-1;
            while (index>0 && nums[index]<=nums[index-1]) --index;
            if (index==0) break;
            --index;
            int index1 = n-1;
            while (nums[index1]<=nums[index]) --index1;
            swap(nums[index], nums[index1]);
            int start = index+1, end = n-1;
            while (start<end) {
                swap(nums[start], nums[end]);
                ++start; --end;
            }
            ans.push_back(nums);
        }
        return ans;
    }
};