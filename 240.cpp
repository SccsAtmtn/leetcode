class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int upperx, uppery, bottomx, bottomy;
        upperx = uppery = 0;
        bottomx = m - 1;
        bottomy = n - 1;
        int t = 0;
        while (!(upperx == bottomx && uppery == bottomy)) {
            if (matrix[upperx][uppery] > target || matrix[bottomx][bottomy] < target) return false;
            if (t == 0) {
                int left = uppery, right = bottomy, ans;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (matrix[upperx][mid] == target) return true;
                    else
                        if (matrix[upperx][mid]<target) {
                            ans = mid;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                }
                bottomy = ans;
                left = upperx;
                right = bottomx;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (matrix[mid][uppery] == target) return true;
                    else
                        if (matrix[mid][uppery]<target) {
                            ans = mid;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                }
                bottomx = ans;
            }
            else {
                int left = upperx, right = bottomx, ans;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (matrix[mid][bottomy] == target) return true;
                    else
                        if (matrix[mid][bottomy]<target) {
                            ans = mid;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                }
                upperx = ans+1;
                left = uppery;
                right = bottomy;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (matrix[bottomx][mid] == target) return true;
                    else
                        if (matrix[bottomx][mid]<target) {
                            ans = mid;
                            left = mid + 1;
                        }
                        else right = mid - 1;
                }
                uppery = ans+1;
            }
            t = 1 - t;
        }
        if (matrix[upperx][uppery] == target) return true;
        else return false;
    }
};