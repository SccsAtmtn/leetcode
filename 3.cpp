class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);
        int len = s.length(), ans = 0;
        if (len==0) return ans;
        int head = 0, tail = 0;
        count[s[0]] = ans = 1;
        while (tail+1<len) {
            ++tail;
            if (count[s[tail]]==0) {
                ans = max(ans, tail-head+1);
                ++count[s[tail]];
            }
            else {
                while (head<tail && count[s[tail]]>0) {
                    --count[s[head]];
                    ++head;
                }
                ++count[s[tail]];
            }
        }
        return ans;
    }
};