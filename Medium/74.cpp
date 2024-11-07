class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int check = matrix[mid / n][mid % n];
            if (check < target) {
                l = mid + 1;
            } else if (check > target) {
                r = mid - 1;
            } else {
                return true;
            }
        }   
        return false;
    }
};