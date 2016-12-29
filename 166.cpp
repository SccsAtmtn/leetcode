#include "head.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        if (numerator==0)
            return "0";
        long long nume = numerator, deno = denominator;
        int sign = (nume*deno>0)?1:-1;
        nume = abs(nume);
        deno = abs(deno);
        ans = to_string(nume/deno);
        nume %= deno;
        if (nume!=0)
            ans = ans+".";
        unordered_map<long long, int> numeIndex;
        while (nume!=0) {
            nume *= 10;
            auto iter = numeIndex.find(nume);
            if (iter==numeIndex.end())
                numeIndex.insert(make_pair(nume, ans.size()));
            else {
                ans = ans+")";
                ans.insert(iter->second, "(");
                if (sign==-1)
                    ans = "-"+ans;
                return ans;
            }
            int nextDigit = nume/deno;
            nume %= deno;
            ans = ans+to_string(nextDigit);
        }
        if (sign==-1)
            ans = "-"+ans;
        return ans;
    }
};
