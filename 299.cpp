class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls, cows;
        bulls = cows = 0;
        int len = secret.length();
        if (len==0) return "0A0B";
        vector<bool> flag(len, true);
        for (int i=0; i<len; ++i)
            if (secret[i]==guess[i]) {
                flag[i] = false;
                ++ bulls;
            }
        for (int i=0; i<len; ++i)
            if (secret[i]!=guess[i])
                for (int j=0; j<len; ++j) 
                    if (flag[j] && guess[j]==secret[i]) {
                        flag[j] = false;
                        ++ cows;
                        break;
                    }
        string ans = intToString(bulls)+"A"+intToString(cows)+"B";
        return ans;
    }
    string intToString(int num) {
        if (num==0) return "0";
        string ans = "";
        while (num>0) {
            ans = (char)(num%10+48)+ans;
            num = num/10;
        }
        return ans;
    }
};