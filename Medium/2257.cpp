class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> guarded(m, vector<bool>(n));
        vector<vector<char>> C(m, vector<char>(n, '.'));
        for (auto g : guards) {
            C[g[0]][g[1]] = 'G';
        }
        for (auto w : walls) {
            C[w[0]][w[1]] = 'W';
        }
        for (int i = 0; i < m; i++) {
            bool gg = false;
            for (int j = 0; j < n; j++) {
                if (C[i][j] == 'G') gg = true;
                else if (C[i][j] == 'W') gg = false;
                else {
                    if (gg) guarded[i][j] = true;
                }
            }
            gg = false;
            for (int j = n - 1; j >= 0; j--) {
                if (C[i][j] == 'G') gg = true;
                else if (C[i][j] == 'W') gg = false;
                else {
                    if (gg) guarded[i][j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            bool gg = false;
            for (int j = 0; j < m; j++) {
                if (C[j][i] == 'G') gg = true;
                else if (C[j][i] == 'W') gg = false;
                else {
                    if (gg) guarded[j][i] = true;
                }
            }
            gg = false;
            for (int j = m - 1; j >= 0; j--) {
                if (C[j][i] == 'G') gg = true;
                else if (C[j][i] == 'W') gg = false;
                else {
                    if (gg) guarded[j][i] = true;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (C[i][j] == 'G' || C[i][j] == 'W') continue;
                // cout << i << ' ' << j << ' ' << guarded[i][j] << '\n';
                ans += !guarded[i][j];
            }
        }
        return ans;
    }
};