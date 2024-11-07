class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        int pre[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pre[i][j] = matrix[i][j];
                if (i > 0) pre[i][j] += pre[i - 1][j];
                if (j > 0) pre[i][j] += pre[i][j - 1];
                if ((i > 0) && (j > 0)) pre[i][j] -= pre[i - 1][j - 1];
            }
        }

        auto sum = [&](int x1, int y1, int x2, int y2) -> int {
            int ret = pre[x2][y2];
            if (x1 > 0) ret -= pre[x1 - 1][y2];
            if (y1 > 0) ret -= pre[x2][y1 - 1];
            if ((x1 > 0) && (y1 > 0)) ret += pre[x1 - 1][y1 - 1];
            return ret;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int side = 1; i + side - 1 < m && j + side - 1 < n; side++) {
                    if (sum(i, j, i + side - 1, j + side - 1) == side * side) {
                        ans++;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};