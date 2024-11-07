class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> R(m), C(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    R[i] = C[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (!R[i]) continue;
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!C[j]) continue;
            for (int i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
};