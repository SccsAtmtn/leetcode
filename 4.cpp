class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m+n)%2==0)
            return (findKthNumber(nums1, 0, nums2, 0, (m+n)/2)+findKthNumber(nums1, 0, nums2, 0, (m+n)/2+1))/2;
        else
            return findKthNumber(nums1, 0, nums2, 0, (m+n)/2+1);
    }
    double findKthNumber(vector<int>& nums1, int p1, vector<int>& nums2, int p2, int k) {
        int m = nums1.size(), n = nums2.size();
        if (m-p1>n-p2) return findKthNumber(nums2, p2, nums1, p1, k);
        if (m-p1==0) return nums2[k-1];
        if (k==1) return min(nums1[p1], nums2[p2]);
        int offset1 = min(k/2, m-p1), offset2 = k-offset1;
        int q1 = p1+offset1-1, q2 = p2+offset2-1;
        if (nums1[q1]<nums2[q2])
            return findKthNumber(nums1, q1+1, nums2, p2, k-offset1);
        else 
            if (nums1[q1]>nums2[q2])
                return findKthNumber(nums1, p1, nums2, q2+1, k-offset2);
            else 
                return nums1[q1];
    }
};