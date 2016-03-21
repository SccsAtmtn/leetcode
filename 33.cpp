class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==0) return -1;
        if (n==1) return (nums[0]==target)?0:-1;
        int left = 0, right = n-1;
        while (left<right) {
            int a = nums[left], b = nums[right];
            if (a==target) return left;
            if (b==target) return right;
            if (a<b) {
                if (target<a || target>b) return -1;
                else {
                    while (left<right) {
                        int mid = left+(right-left)/2;
                        if (target==nums[mid]) return mid;
                        else
                            if (target>nums[mid]) left = mid+1;
                            else right = mid;
                    }
                    if (left==right) return -1;
                }
            }
            else {
                int mid = left+(right-left)/2, c = nums[mid];
                if (target<a && target>b) return -1;
                else {
                    if (target==c) return mid;
                    if (target>a) {
                        if (c>b) 
                            if (c>target) right = mid;
                            else left = mid+1;
                        else right = mid;
                    }
                    else {
                        if (c>b) left = mid+1;
                        else 
                            if (c<target) left = mid+1;
                            else right = mid;
                    }
                }
            }
        }
        return -1;
    }
};