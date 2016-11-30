#include "head.h"

class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        while (start<str.length() && (str[start]==' ' || str[start]=='0'))
            ++start;
        if (start==str.length())
            return 0;
        if ((str[start]!='+') && (str[start]!='-') && !(str[start]>='0' && str[start]<='9'))
            return 0;
        string MAX_STR("2147483647");
        string MIN_STR("2147483648");
        bool isPositive = true; 
        if (str[start]=='-') {
            isPositive = false;
            ++start;
        }
        else if (str[start]=='+')
            ++start;
        if (start==str.length())
            return 0;
        if (!(str[start]>='0' && str[start]<='9'))
            return 0;
        int end = start;
        while (end<str.length() && (str[end]>='0'&& str[end]<='9'))
            ++end;
        string numPart = str.substr(start, end-start);
        start = 0;
        while (numPart[start]=='0')
            ++start;
        numPart = numPart.substr(start);
        if (numPart.length()>MAX_STR.length())
            return (isPositive)?0x7fffffff:0x80000000;
        else if (numPart.length()==MAX_STR.length()) {
            int ans = 0;
            bool isEqual = true;
            for (int i=0; i<numPart.length(); ++i) {
                if (isEqual)
                    if (isPositive)
                        if (numPart[i]>MAX_STR[i])
                            return 0x7fffffff;
                        else if (numPart[i]<MAX_STR[i])
                            isEqual = false;
                        else;
                    else if (numPart[i]>MIN_STR[i])
                            return 0x80000000;
                        else if (numPart[i]<MIN_STR[i])
                            isEqual = false;
                        else;
                ans = ans*10+static_cast<int>(numPart[i]-'0');
            }
            return (isPositive)?ans:-ans;
        }
        else {
            int ans = 0;
            for (int i=0; i<numPart.length(); ++i)
                ans = ans*10+static_cast<int>(numPart[i]-'0');
            return (isPositive)?ans:-ans;
        }
    }
};
