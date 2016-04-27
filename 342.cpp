class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num<=0) return false;
        int a = round(sqrt(num));
        if (a*a!=num) return false;
        unsigned int maxNum = pow(2, 31);
        return maxNum%a==0;
    }
};