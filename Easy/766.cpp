class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        auto check = [&](int r, int c) -> bool {
            int val = matrix[r][c];
            r++, c++;
            while (r < m && c < n) {
                if (matrix[r][c] != val) return false;
                r++, c++;
            }
            return true;
        };

        for (int i = m - 1; i >= 0; i--) {
            if (!check(i, 0)) return false;
        }
        for (int i = 1; i < n; i++) {
            if (!check(0, i)) return false;
        }
        return true;
    }
};