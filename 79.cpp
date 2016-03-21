class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.length();
        int m = board.size();
        if (m==0) return false;
        int n = board[0].size();
        if (n==0) return false;
        vector<bool> one(n, false);
        vector<vector<bool>> searched(m, one);
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (searchBoard(0, i, j, searched, board, word))
                    return true;
        return false;
    }
    bool searchBoard(int current, int x, int y, vector<vector<bool>>& searched, vector<vector<char>>& board, string word) {
        if (searched[x][y]) return false;
        if (board[x][y]!=word[current]) return false;
        if (current==word.length()-1) return true;
        int m = board.size(), n = board[0].size();
        searched[x][y] = true;
        if (x>0) 
            if (searchBoard(current+1, x-1, y, searched, board, word))
                return true;
        if (y>0)
            if (searchBoard(current+1, x, y-1, searched, board, word))
                return true;
        if (x<m-1)
            if (searchBoard(current+1, x+1, y, searched, board, word))
                return true;
        if (y<n-1)
            if (searchBoard(current+1, x, y+1, searched, board, word))
                return true;
        searched[x][y] = false;
        return false;
    }
};