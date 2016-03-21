class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0; i<n-2; ++i) 
            if (i==0 || nums[i]!=nums[i-1]) {
                vector<int> one;
                one.push_back(nums[i]);
                one.push_back(INT_MIN);
                one.push_back(INT_MIN);
                int start = i+1, end = n-1;
                while (start<end) {
                    while (start<end && nums[start]+nums[end]<-nums[i]) ++start;
                    while (start<end && nums[start]+nums[end]>-nums[i]) --end;
                    if (start>=end) break;
                    if (nums[start]+nums[end]==-nums[i]) {
                        if (nums[start]!=one[1]) {
                            one[1] = nums[start];
                            one[2] = nums[end];
                            ans.push_back(one);
                        }
                        ++start;
                        --end;
                    }
                }
            }
        return ans;
    }
};