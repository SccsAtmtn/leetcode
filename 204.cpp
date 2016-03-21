class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> flag(n, true);
        flag[0] = flag[1] = false;
        for (int i=2; i<=round(sqrt(n)); ++i) 
            if (flag[i]) {
                int j = i+i;
                while (j<n) {
                    flag[j] = false;
                    j += i;
                }
            }
        int count = 0;
        for (int i=2; i<n; ++i)
            count += flag[i];
        return count;
    }
};