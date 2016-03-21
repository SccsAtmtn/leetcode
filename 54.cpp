class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m==0) return ans;
        int n = matrix[0].size();
        if (n==0) return ans;
        int x = 0, y = 0;
        int dirx = 0, diry = 1;
        int tot = 1;
        vector<bool> one(n, false);
        vector<vector<bool>> searched(m, one);
        searched[x][y] = true;
        ans.push_back(matrix[x][y]);
        while (tot<m*n) {
            if (x+dirx>=0 && x+dirx<m && y+diry>=0 && y+diry<n && !searched[x+dirx][y+diry]) {
                x += dirx;
                y += diry;
                ans.push_back(matrix[x][y]);
                searched[x][y] = true;
                ++tot;
            }
            else
                if (dirx==0)
                    if (diry==1) {
                        dirx = 1;
                        diry = 0;
                    }
                    else {
                        dirx = -1;
                        diry = 0;
                    }
                else
                    if (dirx==-1) {
                        dirx = 0;
                        diry = 1;
                    } 
                    else {
                        dirx = 0;
                        diry = -1;
                    }
        }
        return ans;
    }
};