#include "head.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int tot = n*n, currentNumber = 0;
        int x = 0, y = 0, dx = 0, dy = 1;
        while (tot>0) {
            ++currentNumber;
            --tot;
            ans[x][y] = currentNumber;
            int nx = x+dx, ny = y+dy;
            if (nx==n || ny==n || nx==-1 || ny==-1 || ans[nx][ny]!=-1) {
                if (dx==1) {
                    dx = 0;
                    dy = -1;
                }
                else if (dx==-1) {
                    dx = 0;
                    dy = 1;
                }
                else if (dy==1) {
                    dx = 1;
                    dy = 0;
                }
                else {
                    dx = -1;
                    dy = 0;
                }
            }
            x += dx;
            y += dy;
        }
        return ans;
    }
};
