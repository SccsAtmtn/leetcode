class Solution {
public:
    vector<string> ans1;
    vector<vector<string>> ans;
    vector<vector<bool>> conquered;
    vector<vector<string>> solveNQueens(int n) {
        string str = "";
        for (int i=0; i<n; ++i) str = str+".";
        vector<bool> one1(n, false);
        for (int i=0; i<n; ++i) {
            ans1.push_back(str);
            conquered.push_back(one1);
        }
        if (n==0) return ans;
        dfs(0, n);
        return ans;
    }
    void dfs(int depth, int n) {
        if (depth==n) {
            ans.push_back(ans1);
            return;
        }
        for (int i=0; i<n; ++i) 
            if (!conquered[depth][i]) {
                vector<vector<bool>> temp(conquered);
                conquered[depth][i] = true;
                int x = depth+1, y = i-1;
                while (x<n && y>=0) {
                    conquered[x][y] = true;
                    ++x; --y;
                }
                x = depth+1; y = i+1;
                while (x<n && y<n) {
                    conquered[x][y] = true;
                    ++x; ++y;
                }
                for (x = depth+1; x<n; ++x)
                    conquered[x][i] = true;
                ans1[depth][i] = 'Q';
                dfs(depth+1, n);
                ans1[depth][i] = '.';
                conquered = temp;
            }
    }
};