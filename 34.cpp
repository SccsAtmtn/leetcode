class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return vector<int>(2, -1);
        vector<int> ans;
        int left = 0, right = nums.size()-1; 
        while (left<right) {
            int mid = left+(right-left)/2;
            if (nums[mid]>=target) right = mid;
            else left = mid+1;
        }
        if (nums[right]!=target) return vector<int>(2, -1);
        ans.push_back(right);
        int end = right;
        left = right;
        right = nums.size()-1;
        while (left<=right) {
            int mid = left+(right-left)/2;
            if (nums[mid]==target) {
                end = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        ans.push_back(end);
        return ans;
    }
};