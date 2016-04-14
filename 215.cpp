 class Solution {
 public:
     int findKthLargest(vector<int>& nums, int k) {
         return quickSelect(nums, 0, nums.size()-1, k);
     }
     int quickSelect(vector<int>& nums, int start, int end, int k) {
         int id = rand()%(end-start+1)+start;
         int mid = start + (end - start) / 2;
         swap(nums[id], nums[mid]);
         int x = nums[mid];
         int left = start, right = end;
         while (left <= right) {
             while (nums[left]>x) ++left;
             while (nums[right]<x) --right;
             if (left <= right)
                 swap(nums[left++], nums[right--]);
         }
         if (right-start+1>=k) return quickSelect(nums, start, right, k);
         else if (left - start >= k) return nums[left - 1];
         else return quickSelect(nums, left, end, k - (left - start));
     }
 };
