class Solution {
public:
    int ans;
    vector<vector<bool>> isConquered;
    int totalNQueens(int n) {
        if (n==0) return 0;
        vector<bool> one(n, false);
        for (int i=0; i<n; ++i)
            isConquered.push_back(one);
        ans = 0;
        dfs(0, n);
        return ans;
    }
    void dfs(int depth, int n) {
        if (depth==n) {
            ++ans;
            return;
        }
        for (int i=0; i<n; ++i) 
            if (!isConquered[depth][i]) {
                vector<vector<bool>> temp(isConquered);
                isConquered[depth][i] = true;
                int x = depth, y = i;
                while (x<n-1 && y>0) {
                    ++x; --y;
                    isConquered[x][y] = true;
                }
                x = depth; y = i;
                while (x<n-1 && y<n-1) {
                    ++x; ++y;
                    isConquered[x][y] = true;
                }
                for (int j=depth+1; j<n; ++j) 
                    isConquered[j][i] = true;
                dfs(depth+1, n);
                isConquered = temp;
            }
    }
};