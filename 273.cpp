class Solution {
public:
    string numberToWords(int num) {
        if (num==0) return "Zero";
        int t = 0;
        string ans = "";
        while (num>0) {
            ++ t;
            int digit = num%100;
            num = num/100;
            if (digit<20) {
                if (ans!="" && ans[0]!=' ') ans = " "+ans;
                switch (digit) {
                    case 1: ans = "One"+ans;break;
                    case 2: ans = "Two"+ans;break;
                    case 3: ans = "Three"+ans;break;
                    case 4: ans = "Four"+ans;break;
                    case 5: ans = "Five"+ans;break;
                    case 6: ans = "Six"+ans;break;
                    case 7: ans = "Seven"+ans;break;
                    case 8: ans = "Eight"+ans;break;
                    case 9: ans = "Nine"+ans;break;
                    case 10: ans = "Ten"+ans;break;
                    case 11: ans = "Eleven"+ans;break;
                    case 12: ans = "Twelve"+ans;break;
                    case 13: ans = "Thirteen"+ans;break;
                    case 14: ans = "Fourteen"+ans;break;
                    case 15: ans = "Fifteen"+ans;break;
                    case 16: ans = "Sixteen"+ans;break;
                    case 17: ans = "Seventeen"+ans;break;
                    case 18: ans = "Eighteen"+ans;break;
                    case 19: ans = "Nineteen"+ans;break;
                    default: break;
                }
            }
            else {
                int one = digit%10;
                digit = digit/10;
                if (ans!="" && ans[0]!=' ') ans = " "+ans;
                switch (one) {
                    case 1: ans = "One"+ans;break;
                    case 2: ans = "Two"+ans;break;
                    case 3: ans = "Three"+ans;break;
                    case 4: ans = "Four"+ans;break;
                    case 5: ans = "Five"+ans;break;
                    case 6: ans = "Six"+ans;break;
                    case 7: ans = "Seven"+ans;break;
                    case 8: ans = "Eight"+ans;break;
                    case 9: ans = "Nine"+ans;break;
                    default: break;
                }
                if (ans!="" && ans[0]!=' ') ans = " "+ans;
                switch (digit) {
                    case 2: ans = "Twenty"+ans;break;
                    case 3: ans = "Thirty"+ans;break;
                    case 4: ans = "Forty"+ans;break;
                    case 5: ans = "Fifty"+ans;break;
                    case 6: ans = "Sixty"+ans;break;
                    case 7: ans = "Seventy"+ans;break;
                    case 8: ans = "Eighty"+ans;break;
                    case 9: ans = "Ninety"+ans;break;
                    default: break;
                }
            }
            if (num>0) {
                digit = num%10;
                num = num/10;
                if (ans!="" && ans[0]!=' ') ans = " "+ans;
                if (digit!=0) ans = "Hundred"+ans;
                switch (digit) {
                    case 1: ans = "One "+ans;break;
                    case 2: ans = "Two "+ans;break;
                    case 3: ans = "Three "+ans;break;
                    case 4: ans = "Four "+ans;break;
                    case 5: ans = "Five "+ans;break;
                    case 6: ans = "Six "+ans;break;
                    case 7: ans = "Seven "+ans;break;
                    case 8: ans = "Eight "+ans;break;
                    case 9: ans = "Nine "+ans;break;
                    default: break;
                }
                if (ans!="" && ans[0]!=' ') ans = " "+ans;
                if (num%1000>0) {
                    if (t==1) ans = "Thousand"+ans;
                    if (t==2) ans = "Million"+ans;
                    if (t==3) ans = "Billion"+ans;
                }
            }
        }
        if (ans[0]==' ') return ans.substr(1, ans.length()-1);
        else return ans;
    }
};