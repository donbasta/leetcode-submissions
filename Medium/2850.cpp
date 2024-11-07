class Solution {
public:
    int dist(pair<int, int> x, pair<int, int> y) {
        return abs(x.first - y.first) + abs(x.second - y.second);
    }
    int minimumMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int e = 0, f = 0;
        vector<pair<int, int>> posa(9), posb(9);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 0) {
                    posa[e++] = make_pair(i, j);
                } else if (grid[i][j] > 1) {
                    for (int k = 0; k < grid[i][j] - 1; k++) {
                        posb[f++] = make_pair(i, j);
                    }
                }
            }
        }
        assert (e == f);
        vector<vector<int>> dp(1 << e, vector<int>(1 << e));
        for (int i = 1; i < (1 << e); i++) {
            for (int j = 1; j < (1 << e); j++) {
                if (__builtin_popcount(i) != __builtin_popcount(j)) continue;
                vector<int> tmpa, tmpb;
                for (int b = 0; b < e; b++) {
                    if ((i >> b) & 1) tmpa.push_back(b);
                    if ((j >> b) & 1) tmpb.push_back(b);
                }
                int tmp = INT_MAX;
                for (auto x : tmpa) {
                    for (auto y : tmpb) {
                        tmp = min(tmp, dist(posa[x], posb[y]) + dp[i ^ (1 << x)][j ^ (1 << y)]);
                    }
                }
                dp[i][j] = tmp;
            }
        }
        return dp[(1 << e) - 1][(1 << e) - 1];
    }
};