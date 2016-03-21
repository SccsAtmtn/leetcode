class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t<0 || k<=0) return false;
        int n = nums.size();
        if (n==0) return false;
        multiset<double> tree;
        for (int i=0; i<n; ++i) {
            if (i>=k+1) {
                multiset<double>::iterator it = tree.find(double(nums[i-k-1]));
                tree.erase(it);
            }
            multiset<double>::iterator st = tree.lower_bound(double(nums[i])-t), ed = tree.upper_bound(double(nums[i])+t);
            if (st!=ed) return true;
            tree.insert(double(nums[i]));
        }
        return false;
    }
};