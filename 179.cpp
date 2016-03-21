 class Solution {
 public:
     string largestNumber(vector<int>& nums) {
         int n = nums.size();
         if (n == 0) return "";
         vector<string> strs;
         for (int i = 0; i<n; ++i)
             strs.push_back(intToStr(nums[i]));
         sort(strs.begin(), strs.end(), cmp);
         string ans("");
         for (int i = 0; i<n; ++i)
             ans = ans + strs[i];
         if (ans[0]=='0') return "0";
         else return ans;
     }
     static bool cmp(string a, string b) {
         return a + b > b + a;
     }
     string intToStr(int x) {
         string ans("");
         if (x == 0) return "0";
         while (x>0) {
             ans = (char)(x % 10 + 48) + ans;
             x /= 10;
         }
         return ans;
     }
 };