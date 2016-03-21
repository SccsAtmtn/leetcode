class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (len==0) return true;
        for (int i=0; i<len; ++i)
            if (s[i]>=65 && s[i]<=90) s[i] = (char)(s[i]+97-65);
        int start = 0, end = len-1;
        while (start<end) {
            while (start<end && !((s[start]>=97 && s[start]<=97+25) || (s[start]>=48 && s[start]<=57))) ++start;
            while (start<end && !((s[end]>=97 && s[end]<=97+25) || (s[end]>=48 && s[end]<=57))) --end;
            if (start>=end) break;
            if (s[start]!=s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};