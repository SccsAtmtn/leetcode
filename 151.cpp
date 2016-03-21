class Solution {
public:
    void reverseWords(string &s) {
        while (s.length()>0 && s[0]==' ') s.erase(0, 1);
        while (s.length()>0 && s[s.length()-1]==' ') s.erase(s.length()-1, 1);
        int current = 0;
        while (current<s.length()) {
            while (current<s.length() && s[current]!=' ') ++current;
            if (current==s.length()) break;
            ++current;
            while (current<s.length() && s[current]==' ') s.erase(current, 1);
        }
        int n = s.length();
        if (n==0) return;
        int start = 0, end = 0;
        while (start<n) {
            while (end<n && s[end]!=' ') ++end;
            if (end==n) end = n-1;
            else --end;
            int next = end+2;
            while (start<end) {
                swap(s[start], s[end]);
                ++start;
                --end;
            }
            while (next<n && s[next]==' ') s.erase(next, 1);
            start = end = next;
        }
        for (int i=0; i<n/2; ++i)
            swap(s[i], s[n-1-i]);
    }
};