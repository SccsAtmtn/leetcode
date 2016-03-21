class Solution {
public:
    int climbStairs(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        int a = 1, b = 2, c = 0, t = 2;
        while (t<n) {
            c = a+b;
            a = b;
            b = c;
            ++ t;
        }
        return b;
    }
};