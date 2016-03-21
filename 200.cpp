class Solution {
public:
    vector<vector<bool>> flag;
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m==0) return 0;
        int n = grid[0].size();
        if (n==0) return 0;
        vector<bool> one(n, false);
        for (int i=0; i<m; ++i)
            flag.push_back(one);
        int ans = 0;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j]=='1' && !flag[i][j]) {
                    ++ans;
                    searchGrid(grid, i, j);
                }
        return ans;
    }
    void searchGrid(vector<vector<char>>& grid, int x, int y) {
        deque<pair<int, int>> que(1, make_pair(x, y));
        flag[x][y] = true;
        int m = grid.size(), n = grid[0].size();
        while (!que.empty()) {
            x = que.front().first;
            y = que.front().second;
            que.pop_front();
            if (x>0 && grid[x-1][y]=='1' && !flag[x-1][y]) {
                flag[x-1][y] = true;
                que.push_back(make_pair(x-1, y));
            }
            if (x<m-1 && grid[x+1][y]=='1' && !flag[x+1][y]) {
                flag[x+1][y] = true;
                que.push_back(make_pair(x+1, y));
            }
            if (y>0 && grid[x][y-1]=='1' && !flag[x][y-1]) {
                flag[x][y-1] = true;
                que.push_back(make_pair(x, y-1));
            }
            if (y<n-1 && grid[x][y+1]=='1' && !flag[x][y+1]) {
                flag[x][y+1] = true;
                que.push_back(make_pair(x, y+1));
            }
        }
    }
};