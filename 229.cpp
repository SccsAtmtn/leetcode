class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if (n==0) return ans;
        vector<int> candidate(2, 0), count(2, 0);
        for (int i=0; i<n; ++i) 
            if (count[0]==0) {
                candidate[0] = nums[i];
                count[0] = 1;
            }
            else
                if (candidate[0]==nums[i]) ++ count[0];
                else
                    if (count[1]==0) {
                        candidate[1] = nums[i];
                        count[1] = 1;
                    }
                    else 
                        if (candidate[1]==nums[i]) ++ count[1];
                        else {
                            -- count[0];
                            -- count[1];
                        }
        count[0] = count[1] = 0;
        for (int i=0; i<n; ++i)
            if (candidate[0]==nums[i]) ++ count[0];
            else
                if (candidate[1]==nums[i]) ++ count[1];
        for (int i=0; i<2; ++i)
            if (count[i]>n/3) ans.push_back(candidate[i]);
        return ans;
    }
};