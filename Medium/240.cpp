class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int id = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if (id == n) continue;
            if (matrix[i][id] == target) {
                return true;
            }
        }
        return false;
    }
};