class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if (rowIndex==0) return ans;
        for (int i=1; i<=rowIndex; ++i) {
            int j = i-1;
            while (j>0) {
                ans[j] += ans[j-1];
                --j;
            }
            ans.push_back(1);
        }
        return ans;
    }
};