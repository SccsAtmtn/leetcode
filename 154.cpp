class Solution {
public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1);
    }
    int binarySearch(vector<int>& nums, int left, int right) {
        if (left==right) return nums[left];
        int mid = left+(right-left)/2;
        if (nums[mid]<nums[right]) 
            return binarySearch(nums, left, mid);
        else
            if (nums[mid]>nums[right])
                return binarySearch(nums, mid+1, right);
            else
                return min(binarySearch(nums, left, mid), binarySearch(nums, mid+1, right));
    }
};