#include "head.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> ans;
        unordered_map<string, pair<int, vector<string>>> father;
        deque<pair<string, int>> q;
        auto it = wordList.find(beginWord);
        if (it==wordList.end()) 
            wordList.insert(beginWord);
        it = wordList.find(endWord);
        if (it==wordList.end())    
            wordList.insert(endWord);
        for (auto x : wordList) 
            father.insert(make_pair(x, make_pair(-1, vector<string>{})));
        auto itr = father.find(endWord);
        q.push_back(make_pair(endWord, 0));
        itr->second.first = 0;
        while (!q.empty()) {
            string str = q.front().first;
            int step = q.front().second;
            q.pop_front();
            for (int i = 0; i<str.length(); ++i) {
                for (char ch='a'; ch<='z'; ++ch) 
                    if (str[i]!=ch) {
                        string newStr{str};
                        newStr[i] = ch;
                        itr = father.find(newStr);
                        if (itr!=father.end()) {
                            if (itr->second.first!=-1) {
                                if (itr->second.first==step+1) 
                                    itr->second.second.push_back(str);
                            }
                            else {
                                itr->second.first = step+1;
                                itr->second.second.push_back(str);
                                if (newStr!=beginWord)
                                    q.push_back(make_pair(newStr, step+1));
                            }
                        }
                    }
            }
        }
        vector<string> temp;
        dfs(father, temp, beginWord, endWord, ans);
        return ans;
    }
    void dfs(unordered_map<string, pair<int, vector<string>>> &father, vector<string> &temp, string beginWord, string endWord, vector<vector<string>> &ans) {
        temp.push_back(beginWord);
        if (beginWord==endWord) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        auto itr = father.find(beginWord);
        for (string str : itr->second.second)
            dfs(father, temp, str, endWord, ans);
        temp.pop_back();
    } 
};
