#include "head.h"

class Solution {
public:
    using boolArray = vector<vector<bool>>;
    void solveSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false)), cols(9, vector<bool>(9, false)), blocks(9, vector<bool>(9, false));
        for (int i=0; i<9; ++i)
            for (int j=0; j<9; ++j)
                if (board[i][j]!='.') {
                    rows[i][board[i][j]-'1'] = true;
                    cols[j][board[i][j]-'1'] = true;
                    int blockID = i/3*3+j/3;
                    blocks[blockID][board[i][j]-'1'] = true;
                }
        dfsToSolve(board, rows, cols, blocks, 0, 0);
    }
    bool dfsToSolve(vector<vector<char>> &board, boolArray &rows, boolArray &cols, boolArray &blocks, int x, int y) {
        if (x==9)
            return true;
        if (board[x][y]!='.')
            if (y==8) {
                if (dfsToSolve(board, rows, cols, blocks, x+1, 0))
                    return true;
            }
            else {
                if (dfsToSolve(board, rows, cols, blocks, x, y+1))
                    return true;
            }
        else {
            int blockID = x/3*3+y/3;
            for (char ch='1'; ch<='9'; ++ch)
                if (rows[x][ch-'1'] || cols[y][ch-'1'] || blocks[blockID][ch-'1'])
                    continue;
                else {
                    board[x][y] = ch;
                    rows[x][ch-'1'] = cols[y][ch-'1'] = blocks[blockID][ch-'1'] = true;
                    if (y==8)
                        if (dfsToSolve(board, rows, cols, blocks, x+1, 0))
                            return true;
                        else;
                    else
                        if (dfsToSolve(board, rows, cols, blocks, x, y+1))
                            return true;
                    rows[x][ch-'1'] = cols[y][ch-'1'] = blocks[blockID][ch-'1'] = false;
                    board[x][y] = '.';
                }
        }
        return false;
    }
};
