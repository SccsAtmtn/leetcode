class Solution {
public:
    bool isHappy(int n) {
        if (n==1) return true;
        int maxNum = 9*9*12;
        vector<bool> flag(maxNum, false);
        if (n<maxNum) flag[n] = true;
        while (true) {
            int m = 0;
            while (n>0) {
                int x = n%10;
                m += x*x;
                n = n/10;
            }
            n = m;
            if (n==1) return true;
            if (flag[n]) return false;
            flag[n] = true;
        }
    }
};