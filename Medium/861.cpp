class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int val[m];
        for (int i = 0; i < m; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += (grid[i][j] * (1 << (n - 1 - j)));
            }
            val[i] = tmp;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                val[i] = val[i] ^ ((1 << n) - 1);
            }
            ans += (1 << (n - 1));
        }
        for (int i = 1; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                cnt += ((val[j] >> (n - 1 - i)) & 1);
            }
            ans += max(cnt, m - cnt) * (1 << (n - 1 - i));
        }
        return ans;
    }
};