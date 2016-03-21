class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size()<2 || k==0) return false;
        if (k>=nums.size()) k = nums.size()-1;
        set<int> tree;
        for (int i=0; i<=k; ++i) 
            tree.insert(nums[i]);
        if (tree.size()<k+1) return true;
        if (k<nums.size()-1) 
            for (int i=1; i<nums.size()-k; ++i) {
                set<int>::iterator it = tree.find(nums[i-1]);
                tree.erase(it);
                tree.insert(nums[i+k]);
                if (tree.size()<k+1) return true;
            }
        return false;
    }
};