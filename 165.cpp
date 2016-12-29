#include "head.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ptr1 = 0, ptr2 = 0;
        while (ptr1!=version1.size() && ptr2!=version2.size()) {
            int num1 = 0, num2 = 0;
            while (ptr1!=version1.size() && version1[ptr1]!='.')
                num1 = num1*10+version1[ptr1++]-'0';
            while (ptr2!=version2.size() && version2[ptr2]!='.')
                num2 = num2*10+version2[ptr2++]-'0';
            if (num1<num2)
                return -1;
            else if (num1>num2)
                return 1;
            if (ptr1!=version1.size())
                ++ptr1;
            if (ptr2!=version2.size())
                ++ptr2;
        }
        
        while (ptr1!=version1.size()) {
            int num1 = 0;
            while (ptr1!=version1.size() && version1[ptr1]!='.')
                num1 = num1*10+version1[ptr1++]-'0';
            if (num1!=0)
                return 1;
            if (ptr1!=version1.size())
                ++ptr1;
        }
        while (ptr2!=version2.size()) {
            int num2 = 0;
            while (ptr2!=version2.size() && version2[ptr2]!='.')
                num2 = num2*10+version2[ptr2++]-'0';
            if (num2!=0)
                return -1;
            if (ptr2!=version2.size())
                ++ptr2;
        }
        return 0;
    }
};
