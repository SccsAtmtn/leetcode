class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int zero = 0xffffffff, one = 0, two = 0, d1, d2, d3;
        for (int i=0; i<nums.size(); ++i)
            one ^= nums[i];
        vector<int> ans;
        int d = 1;
        while ((d & one)==0) d = d << 1; 
        d1 = d2 = 0;
        for (int i=0; i<nums.size(); ++i) {
            if ((d&nums[i])==0) d1 ^= nums[i];
            else d2 ^= nums[i];
        }
        ans.push_back(d1);
        ans.push_back(d2);
        return ans;
    }
};