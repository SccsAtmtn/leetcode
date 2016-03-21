class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        for (long i=1; i<=n; i *= 10) {
            int a = n/i, b = n % i;
            ans += (a+8)/10*i+(a % 10==1)*(b+1);
        }
        return ans;
    }
};