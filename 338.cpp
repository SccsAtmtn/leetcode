class Solution {
public:
    vector<int> countBits(int num) {
        int pre = 0;
        vector<int> ans(num+1, 0);
        for (int i=1; i<=num; ++i) 
            if (i&(i-1)) {
                ans[i] = ans[i-pre]+1;
            }
            else {
                pre = i;
                ans[i] = 1;
            }
        return ans;
    }
};