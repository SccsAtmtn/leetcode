class Solution {
public:
    int reverse(int x) {
        bool flag = (x<0);
        x = (x<0)?-x:x;
        long long ans = 0;
        while (x>0) {
            ans = ans*10+x%10;
            x /= 10;
        }
        if (!flag && ans>0x7fffffff)
            return 0;
        int MIN_INT = 0x80000000;
        long long MAX_NEG = -static_cast<long long>(MIN_INT);        
	    if (flag && ans>MAX_NEG)
            return 0;
        ans = (flag)?-ans:ans;
        return static_cast<int>(ans);
    }
};
