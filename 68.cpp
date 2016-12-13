#include "head.h"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ans;
        if (words.size()==0)
            return ans;
        int start = 0;
        while (start<words.size()) {
            int len = words[start].length();
            int end = start+1;
            while (end<words.size() && len+1+words[end].length()<=maxWidth) {
                len += 1+words[end].length();
                ++end;
            }
            string current = words[start];
            if (end==words.size()) {
                for (int i=start+1; i<end; ++i) 
                    current = current+' '+words[i];
                while (current.length()<maxWidth)
                    current = current+' ';
            }
            else {
                int spaceCnt = maxWidth-len, wordCnt = end-start;
                if (wordCnt>1) {
                    int baseSpace = spaceCnt/(wordCnt-1)+1;
                    spaceCnt = spaceCnt%(wordCnt-1);
                    for (int i=start+1; i<end; ++i) {
                        for (int j=0; j<baseSpace; ++j)
                            current = current+' ';
                        if (i-start<=spaceCnt)
                            current = current+' ';
                        current = current+words[i];
                    }
                }
                else 
                    while (current.length()<maxWidth)
                        current = current+' ';
            }
            ans.push_back(current);
            start = end;
        }
        return ans;
    }
};
