class NumMatrix {
public:
    vector<vector<int> > sum;
    
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m==0) return;
        int n = matrix[0].size();
        if (n==0) return;
        vector<int> none(n, 0);
        for (int i=0; i<m; ++i) sum.push_back(none);
        sum[0][0] = matrix[0][0];
        for (int j=1; j<n; ++j) sum[0][j] = sum[0][j-1]+matrix[0][j];
        for (int i=1; i<m; ++i) {
            int sumRow = 0;
            for (int j=0; j<n; ++j) {
                sumRow += matrix[i][j];
                sum[i][j] = sum[i-1][j]+sumRow;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1==0)
            if (col1==0) return sum[row2][col2];
            else return sum[row2][col2]-sum[row2][col1-1];
        else
            if (col1==0) return sum[row2][col2]-sum[row1-1][col2];
            else return sum[row2][col2]-sum[row2][col1-1]-sum[row1-1][col2]+sum[row1-1][col1-1];
    }
};