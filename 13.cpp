class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mapping;
        mapping.insert(make_pair('I', 1));
        mapping.insert(make_pair('V', 5));
        mapping.insert(make_pair('X', 10));
        mapping.insert(make_pair('L', 50));
        mapping.insert(make_pair('C', 100));
        mapping.insert(make_pair('D', 500));
        mapping.insert(make_pair('M', 1000));
        int previous = 0, ans = 0;
        for (int i=s.length()-1; i>=0; --i) {
            map<char, int>::iterator current = mapping.find(s[i]);
            if (current->second<previous)
                ans -= current->second;
            else
                ans += current->second;
            previous = current->second;
        }
        return ans;
    }
};