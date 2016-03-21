 class Solution {
 public:
     vector<int> findSubstring(string s, vector<string>& words) {
         int lenS = s.length(), n = words.size(), lenWord = words[0].length();
         unordered_map<string, pair<int, int>> tree;
         vector<int> ans;
         for (int i = 0; i < n; ++i) {
             auto ptr = tree.find(words[i]);
             if (ptr == tree.end())
                 tree.insert(make_pair(words[i], make_pair(0, 1)));
             else
                 ++ptr->second.second;
         }
         for (int i = 0; i<lenS - n*lenWord + 1; ++i) {
             int j;
             for (j = i; j<i + n*lenWord; j += lenWord) {
                 string cur = s.substr(j, lenWord);
                 auto ptr = tree.find(cur);
                 if (ptr == tree.end()) break;
                 if (ptr->second.first>=ptr->second.second) break;
                 ++(ptr->second.first);
             }
             if (j == i + n*lenWord)
                 ans.push_back(i);
             for (auto ptr = tree.begin(); ptr != tree.end(); ++ptr)
                 ptr->second.first = 0;
         }
         return ans;
     }
 };