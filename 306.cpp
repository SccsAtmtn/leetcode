class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for (int i = 1; i<n / 2+1; ++i)
            for (int j = 1; j<min((n - i) / 2, n - 2 * i)+1; ++j)
                if (judge(num, i, j)) return true;
        return false;
    }

    bool judge(string num, int len1, int len2) {
        int index = 0, n = num.length(), a = 0, b = 1, c = 2;
        vector<vector<int> > number(3, vector<int>());
        number[a] = stringToInt(num.substr(index, len1));
        index = index + len1;
        number[b] = stringToInt(num.substr(index, len2));
        index = index + len2;
        while (index<n) {
            number[c] = add(number[a], number[b]);
            string nums = intToString(number[c]);
            if (nums != num.substr(index, nums.size()))
                return false;
            int t = a;
            a = b; b = c; c = t;
            len1 = len2; len2 = nums.size();
            index = index + len2;
        }
        return true;
    }
    vector<int> stringToInt(string str) {
        vector<int> num;
        for (int i = 0; i<str.length(); ++i)
            num.push_back((int)str[i] - 48);
        return num;
    }
    vector<int> add(vector<int> a, vector<int> b) {
        vector<int> c;
        int bit = 0, lena = a.size(), lenb = b.size();
        for (int i = 1; i <= min(lena, lenb); ++i) {
            int sum = a[lena - i] + b[lenb - i] + bit;
            c.push_back(sum % 10);
            bit = sum / 10;
        }
        if (lena>lenb) {
            for (int i = lenb + 1; i<lena + 1; ++i) {
                int sum = a[lena - i] + bit;
                c.push_back(sum % 10);
                bit = sum / 10;
            }
        }
        else
            for (int i = lena + 1; i<lenb + 1; ++i) {
                int sum = b[lenb - i] + bit;
                c.push_back(sum % 10);
                bit = sum / 10;
            }
        if (bit>0) c.push_back(bit);
        vector<int> ans;
        for (int i = 1; i <= c.size(); ++i)
            ans.push_back(c[c.size() - i]);
        return ans;
    }
    string intToString(vector<int> a) {
        string ans;
        for (int i = 0; i<a.size(); ++i) {
            ans = ans+(char)(a[i]+48);
        }
        return ans;
    }
};