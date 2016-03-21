class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> number1 = strToVec(num1), number2 = strToVec(num2);
        int n1 = number1.size(), n2 = number2.size();
        vector<int> ans(n1+n2+1, 0);
        for (int i=0; i<n1; ++i) 
            for (int j=0; j<n2; ++j) {
                ans[i+j] += number1[i]*number2[j];
                ans[i+j+1] += (ans[i+j]/10);
                ans[i+j] = ans[i+j]%10;
            }
        while (ans[ans.size()-1]==0) ans.pop_back();
        string ansStr("");
        for (int i=ans.size()-1; i>=0; --i)
            ansStr = ansStr+char(ans[i]+48);
        if (ansStr.length()==0) return "0";
        else return ansStr;
    }
    vector<int> strToVec(string num) {
        vector<int> number;
        for (int i=num.length()-1; i>=0; --i)
            number.push_back(int(num[i])-48);
        return number;
    }
};