#include "head.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int m = board.size();
        if (m!=9)
            return false;
        int n = board[0].size();
        if (n!=9)
            return false;
        for (int i=0; i<9; ++i) {
            vector<bool> occupied(9, false);
            for (int j=0; j<9; ++j)
                if (board[i][j]=='.')
                    continue;
                else if (!(board[i][j]>='1' && board[i][j]<='9'))
                    return false;
                else if (occupied[board[i][j]-'1'])
                    return false;
                else 
                    occupied[board[i][j]-'1'] = true;
        }
        for (int j=0; j<9; ++j) {
            vector<bool> occupied(9, false);
            for (int i=0; i<9; ++i)
                if (board[i][j]=='.')
                    continue;
                else if (occupied[board[i][j]-'1'])
                    return false;
                else 
                    occupied[board[i][j]-'1'] = true;
        }
        for (int k=0; k<9; ++k) {
            int startx = k/3*3, starty = k%3*3;
            vector<bool> occupied(9, false);
            for (int i = startx; i<startx+3; ++i)
                for (int j=starty; j<starty+3; ++j)
                    if (board[i][j]=='.')
                        continue;
                    else if (occupied[board[i][j]-'1'])
                        return false;
                    else
                        occupied[board[i][j]-'1'] = true;
        }
        return true;
    }
};
