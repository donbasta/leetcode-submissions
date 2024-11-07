class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> prob(n, vector<double>(n));
        prob[row][column] = 1.0;
        int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
        int dy[] = {2, -2, 1, -1, 2, -2, 1, -1}; 
        for (int i = 0; i < k; i++) {
            vector<vector<double>> tmp(n, vector<double>(n));
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    for (int mv = 0; mv < 8; mv++) {
                        int nr = r + dx[mv], nc = c + dy[mv];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            tmp[r][c] += prob[nr][nc] / 8.0;
                        }
                    }
                }
            }
            prob = tmp;
        }
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += prob[i][j];
            }
        }
        return ans;
    }
};