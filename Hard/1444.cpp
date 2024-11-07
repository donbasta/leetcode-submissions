class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].length();
        const int INF = 2e9;
        vector<vector<vector<int>>> DP(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -INF)));

        //create 2d prefix sum to count apples
        vector<vector<int>> pref(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
            }
        }
        const function<int(int, int, int, int)> getCountApples = [&](int p, int q, int r, int s) -> int {
            return pref[r][s] - pref[r][q - 1] - pref[p - 1][s] + pref[p - 1][q - 1];
        };

        const int MOD = 1e9 + 7;
        const function<int(int, int, int)> dp = [&](int x, int y, int z) -> int {
            if (DP[x][y][z] != -INF) return DP[x][y][z];
            if (z == 1) return DP[x][y][z] = (getCountApples(x, y, m, n) > 0);
            int tmp = 0;
            for (int i = x + 1; i <= m; i++) {
                if (getCountApples(x, y, i - 1, n) == 0) continue;
                tmp = (tmp + dp(i, y, z - 1)) % MOD;
            }
            for (int j = y + 1; j <= n; j++) {
                if (getCountApples(x, y, m, j - 1) == 0) continue;
                tmp = (tmp + dp(x, j, z - 1)) % MOD;
            }
            return DP[x][y][z] = tmp;
        };
        return dp(1, 1, k);
    }
};