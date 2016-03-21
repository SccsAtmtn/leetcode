class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size()==0) return ans;
        string str = "";
        int index = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (str=="") {
                str = intToString(nums[i]);
                if (i==nums.size()-1 || nums[i]+1!=nums[i+1]) {
                    ans.push_back(str);
                    str = "";
                }
            }
            else 
                if (nums[i+1]-nums[i]==1) continue;
                else {
                    str = str+"->"+intToString(nums[i]);
                    ans.push_back(str);
                    str = "";
                }
        }
        return ans;
    }
    string intToString(int x) {
        if (x==0) return "0";
        if (x==0x80000000) return "-2147483648";
        bool flag = false;
        if (x<0) {
            x = -x;
            flag = true;
        }
        string ans = "";
        while (x>0) {
            ans = (char)(x%10+48)+ans;
            x = x/10;
        }
        if (flag)
            ans = "-"+ans;
        return ans;
    }
};