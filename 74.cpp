class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) return false;
        int n = matrix[0].size();
        if (n==0) return false;
        int ansRow = -1;
        int left = 0, right = m-1;
        while (left<=right) {
            int mid = left+(right-left)/2;
            if (matrix[mid][0]<=target) {
                ansRow = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        if (ansRow==-1) return false;
        left = 0;
        right = n-1;
        while (left<=right) {
            int mid = left+(right-left)/2;
            if (matrix[ansRow][mid]==target) return true;
            else if (matrix[ansRow][mid]>target) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};