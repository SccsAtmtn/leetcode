class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size()==0 || k==0) return ans;
        multiset<int> tree;
        for (int i=0; i<k; ++i)
            tree.insert(nums[i]);
        multiset<int>::iterator it = tree.end();
        --it;
        ans.push_back(*it);
        if (k<nums.size()) 
            for (int i=1; i<=nums.size()-k; ++i) {
                it = tree.find(nums[i-1]);
                tree.erase(it);
                tree.insert(nums[i+k-1]);
                it = tree.end();
                --it;
                ans.push_back(*it);
            }
        return ans;
    }
};