class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index1 = 0, index2 = 0;
        while (index2 <nums.size()) {
            while (index1<nums.size() && nums[index1]!=0) ++index1;
            if (index1==nums.size()) break;
            int index2 = index1;
            while (index2<nums.size() && nums[index2]==0) ++index2;
            if (index2==nums.size()) break;
            while (index2<nums.size() && nums[index1]==0 && nums[index2]!=0) {
                nums[index1] = nums[index2];
                nums[index2] = 0;
                ++ index1;
                ++ index2;
            }
        }
    }
};