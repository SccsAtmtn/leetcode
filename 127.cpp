class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord==endWord) return 1;
        unordered_set<string> searched;
        deque<pair<string, int>> que(1, make_pair(beginWord, 1));
        searched.insert(beginWord);
        while (!que.empty()) {
            string str = que.front().first;
            int step = que.front().second;
            que.pop_front();
            for (int i=0; i<str.length(); ++i)
                for (int ch = 0; ch<26; ++ch)
                    if (str[i]!=(char)(ch+97)) {
                        string str1(str);
                        str1[i] = (char)(ch+97);
                        if (str1==endWord) return step+1;
                        if (wordList.find(str1)!=wordList.end() && searched.find(str1)==searched.end()) {
                            searched.insert(str1);
                            que.push_back(make_pair(str1, step+1));
                        }
                    }
        }
        return 0;
    }
};