class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*
        11:0->0
        12:0->1
        21:1->0
        22:1->1
        */
        int m = board.size();
        if (m<=0) return;
        int n = board[0].size();
        if (n<=0) return;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                int imin = max(0, i-1);
                int imax = min(m-1, i+1);
                int jmin = max(0, j-1);
                int jmax = min(n-1, j+1);
                int tot = 0-board[i][j];
                for (int i=imin; i<=imax; ++i)
                    for (int j=jmin; j<=jmax; ++j)
                        if (board[i][j]==1 || board[i][j]==21 || board[i][j]==22) ++tot;
                if (board[i][j]==1)
                    if (tot==2 || tot==3) board[i][j] = 22;
                    else board[i][j] = 21;
                else
                    if (tot==3) board[i][j] = 12;
                    else board[i][j] = 11;
            }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] = board[i][j]%10-1;
    }
};