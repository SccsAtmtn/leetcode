class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n<2) return 0;
        int ans = 0;
        vector<int> nums;
        for (int i=0; i<n; ++i) {
            int t = 0;
            string s = words[i];
            int len = s.length();
            for (int j=0; j<len; ++j) 
                t |= (1<<((int)s[j]-97));
            nums.push_back(t);
        }
        for (int i=0; i<n-1; ++i)
            for (int j=i+1; j<n; ++j) 
                if ((nums[i] & nums[j])==0)
                    ans = max(ans, (int)((words[i].length())*(words[j].length())));
        return ans;
    }
};