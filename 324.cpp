class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return;
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int t = n-1;
        for (int i=1; i<n; i += 2) {
            nums[i] = temp[t];
            --t;
        }
        for (int i=0; i<n; i += 2) {
            nums[i] = temp[t];
            --t;
        }
    }
};