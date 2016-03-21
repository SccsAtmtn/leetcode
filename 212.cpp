class Solution {
public:
    class TrieNode {
    public:
        vector<TrieNode *> sons;
        char key;
        bool end, inAns;
        TrieNode(char key = '#'): key(key), end(false), inAns(false) {};
    };
    TrieNode * root;
    vector<string> ans;
    Solution() {
        root = new TrieNode();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        int m = board.size();
        if (m==0) return ans;
        int n = board[0].size();
        if (n==0) return ans;
        vector<bool> one(n, false);
        vector<vector<bool>> searched(m, one);
        string str("");
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                searchBoard(root, i, j, searched, board, str);
        return ans;
    }
    void buildTrie(vector<string> & words) {
        for (int i=0; i<words.size(); ++i) {
            TrieNode * current = root;
            for (int j=0; j<words[i].size(); ++j) {
                TrieNode * next = NULL;
                for (int k=0; k<current->sons.size(); ++k) 
                    if (current->sons[k]->key==words[i][j]) {
                        next = current->sons[k];
                        break;
                    }
                if (!next) {
                    next = new TrieNode(words[i][j]);
                    current->sons.push_back(next);
                }
                current = next;
            }
            current->end = true;
        }
    }
    void searchBoard(TrieNode * current, int x, int y, vector<vector<bool>>& searched, vector<vector<char>>& board, string& str) {
        if (searched[x][y]) return;
        int m = board.size(), n = board[0].size();
        TrieNode * next = NULL;
        for (int i=0; i<current->sons.size(); ++i)
            if (current->sons[i]->key==board[x][y]) {
                next = current->sons[i];
                break;
            }
        if (!next) return;
        searched[x][y] = true;
        str = str+board[x][y];
        if (next->end && !next->inAns) {
            ans.push_back(str);
            next->inAns = true;
        }
        if (x>0) searchBoard(next, x-1, y, searched, board, str);
        if (y>0) searchBoard(next, x, y-1, searched, board, str);
        if (x<m-1) searchBoard(next, x+1, y, searched, board, str);
        if (y<n-1) searchBoard(next, x, y+1, searched, board, str);
        str.erase(str.length()-1, 1);
        searched[x][y] = false;
    }
};