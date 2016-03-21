class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> opt(amount+1, 0);
        for (int i=1; i<=amount; ++i)
            opt[i] = 0x7fffffff;
        for (int i=1; i<=amount; ++i)
            for (int j=0; j<coins.size(); ++j) 
                if (i-coins[j]>=0 && opt[i-coins[j]]!=0x7fffffff && opt[i-coins[j]]+1<opt[i])
                    opt[i] = opt[i-coins[j]]+1;
        return (opt[amount]!=0x7fffffff)?opt[amount]:-1;
    }
};