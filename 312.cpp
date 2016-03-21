class Solution {
public:
    int inf = (int)1e9;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        vector<vector<int> > f(n+1, vector<int>(n+2, -inf));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for (int j=0; j<n+1; ++j)
            f[j][1] = 0;
        for (int i=2; i<n+2; ++i) 
            for (int j=0; j<n+2-i; ++j)
                for (int k=1; k<i; ++k)
                    f[j][i] = max(f[j][i], f[j][k]+f[j+k][i-k]+nums[j+k]*nums[j]*nums[j+i]);
        return f[0][n+1];
    }
};