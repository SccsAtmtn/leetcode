class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m==0) return;
        int n = board[0].size();
        if (n==0) return;
        vector<bool> one(n, false);
        vector<vector<bool>> flag(m, one);
        for (int i=0; i<m; ++i) {
            if (board[i][0]=='O' && !flag[i][0]) {
                deque<pair<int, int>> que(1, make_pair(i, 0));
                flag[i][0] = true;
                while (!que.empty()) {
                    int x = que.front().first, y = que.front().second;
                    que.pop_front();
                    if (x>0 && board[x-1][y]=='O' && !flag[x-1][y]) {
                        flag[x-1][y] = true;
                        que.push_back(make_pair(x-1, y));
                    }
                    if (x<m-1 && board[x+1][y]=='O' && !flag[x+1][y]) {
                        flag[x+1][y] = true;
                        que.push_back(make_pair(x+1, y));
                    }
                    if (y>0 && board[x][y-1]=='O' && !flag[x][y-1]) {
                        flag[x][y-1] = true;
                        que.push_back(make_pair(x, y-1));
                    }
                    if (y<n-1 && board[x][y+1]=='O' && !flag[x][y+1]) {
                        flag[x][y+1] = true;
                        que.push_back(make_pair(x, y+1));
                    }
                }
            }
            if (board[i][n-1]=='O' && !flag[i][n-1]) {
                deque<pair<int, int>> que(1, make_pair(i, n-1));
                flag[i][n-1] = true;
                while (!que.empty()) {
                    int x = que.front().first, y = que.front().second;
                    que.pop_front();
                    if (x>0 && board[x-1][y]=='O' && !flag[x-1][y]) {
                        flag[x-1][y] = true;
                        que.push_back(make_pair(x-1, y));
                    }
                    if (x<m-1 && board[x+1][y]=='O' && !flag[x+1][y]) {
                        flag[x+1][y] = true;
                        que.push_back(make_pair(x+1, y));
                    }
                    if (y>0 && board[x][y-1]=='O' && !flag[x][y-1]) {
                        flag[x][y-1] = true;
                        que.push_back(make_pair(x, y-1));
                    }
                    if (y<n-1 && board[x][y+1]=='O' && !flag[x][y+1]) {
                        flag[x][y+1] = true;
                        que.push_back(make_pair(x, y+1));
                    }
                }
            }
        }
        for (int i=0; i<n; ++i) {
            if (board[0][i]=='O' && !flag[0][i]) {
                deque<pair<int, int>> que(1, make_pair(0, i));
                flag[0][i] = true;
                while (!que.empty()) {
                    int x = que.front().first, y = que.front().second;
                    que.pop_front();
                    if (x>0 && board[x-1][y]=='O' && !flag[x-1][y]) {
                        flag[x-1][y] = true;
                        que.push_back(make_pair(x-1, y));
                    }
                    if (x<m-1 && board[x+1][y]=='O' && !flag[x+1][y]) {
                        flag[x+1][y] = true;
                        que.push_back(make_pair(x+1, y));
                    }
                    if (y>0 && board[x][y-1]=='O' && !flag[x][y-1]) {
                        flag[x][y-1] = true;
                        que.push_back(make_pair(x, y-1));
                    }
                    if (y<n-1 && board[x][y+1]=='O' && !flag[x][y+1]) {
                        flag[x][y+1] = true;
                        que.push_back(make_pair(x, y+1));
                    }
                }
            }
            if (board[m-1][i]=='O' && !flag[m-1][i]) {
                deque<pair<int, int>> que(1, make_pair(m-1, i));
                flag[m-1][i] = true;
                while (!que.empty()) {
                    int x = que.front().first, y = que.front().second;
                    que.pop_front();
                    if (x>0 && board[x-1][y]=='O' && !flag[x-1][y]) {
                        flag[x-1][y] = true;
                        que.push_back(make_pair(x-1, y));
                    }
                    if (x<m-1 && board[x+1][y]=='O' && !flag[x+1][y]) {
                        flag[x+1][y] = true;
                        que.push_back(make_pair(x+1, y));
                    }
                    if (y>0 && board[x][y-1]=='O' && !flag[x][y-1]) {
                        flag[x][y-1] = true;
                        que.push_back(make_pair(x, y-1));
                    }
                    if (y<n-1 && board[x][y+1]=='O' && !flag[x][y+1]) {
                        flag[x][y+1] = true;
                        que.push_back(make_pair(x, y+1));
                    }
                }
            }
        }
        for (int i=0; i<m; ++i) 
            for (int j=0; j<n; ++j)
                if (board[i][j]=='O' && !flag[i][j])
                    board[i][j] = 'X';
    }
};