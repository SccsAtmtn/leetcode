class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> &nums) {
        int n = nums.size();
        if (n==0) return;
        sum.push_back(nums[0]);
        for (int i=1; i<n; ++i)
            sum.push_back(sum[i-1]+nums[i]);
    }

    int sumRange(int i, int j) {
        if (i==0) return sum[j];
        else
            return sum[j]-sum[i-1];
    }
};
