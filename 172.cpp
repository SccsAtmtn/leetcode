class Solution {
public:
    int trailingZeroes(int n) {
        if (n==0) return 0;
        int ans = 0;
        int pow = 5;
        while (pow<=n) {
            ans += n/pow;
            if (pow<=n/5) pow *= 5;
            else break;
        }
        return ans;
    }
};