class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        if (nums.size()==0) return output;
        double product = 1;
        int count = 0;
        for (int i=0; i<nums.size(); ++i)
            if (nums[i]!=0) product *= nums[i];
            else ++ count;
        for (int i=0; i<nums.size(); ++i)
            if (nums[i]!=0)
                if (count==0) output.push_back(round(product/nums[i]));
                else output.push_back(0);
            else
                if (count==1) output.push_back(product);
                else output.push_back(0);
        return output;
    }
};