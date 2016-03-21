 class Solution {
 public:
     vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
         int m = nums1.size(), n = nums2.size();
         vector<vector<int>> f1 = optimize(nums1);
         vector<vector<int>> f2 = optimize(nums2);
         vector<int> ans(k, 0);
         for (int i = max(0, k-n); i <= min(m, k); ++i) {
             vector<int> g1 = f1[i];
             vector<int> g2 = f2[k - i];
             vector<int> temp;
             int pointer1 = 0, pointer2 = 0;
             while (pointer1<i && pointer2<k - i) {
                 if (!lexicographical_compare(g1.begin()+pointer1, g1.end(), g2.begin()+pointer2, g2.end()))
                     temp.push_back(g1[pointer1++]);
                 else
                     temp.push_back(g2[pointer2++]);
             }
             while (pointer1<i)
                 temp.push_back(g1[pointer1++]);
             while (pointer2<k - i)
                 temp.push_back(g2[pointer2++]);
             for (int j = 0; j<k; ++j)
                 if (temp[j]>ans[j]) {
                     ans = temp;
                     break;
                 }
                 else
                     if (temp[j] < ans[j]) break;
         }
         return ans;
     }
     vector<vector<int>> optimize(vector<int> & nums) {
         int n = nums.size();
         vector<vector<int>> ans(n + 1);
         ans[n] = nums;
         for (int i = n - 1; i >= 0; --i) {
             ans[i] = ans[i + 1];
             for (int j = 1; j < ans[i].size(); ++j)
                 if (ans[i][j]>ans[i][j - 1]) {
                     ans[i].erase(ans[i].begin()+j-1);
                     break;
                 }
             ans[i].resize(i);
         }
         return ans;
     }
 };