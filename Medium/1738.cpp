class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int F[m][n];
        vector<int> ve;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                F[i][j] = matrix[i][j];
                if (i > 0) F[i][j] ^= F[i - 1][j];
                if (j > 0) F[i][j] ^= F[i][j - 1];
                if ((i > 0) && (j > 0)) F[i][j] ^= F[i - 1][j - 1];
                ve.emplace_back(F[i][j]);
            }
        }
        sort(ve.rbegin(), ve.rend());
        return ve[k - 1];
    }
};