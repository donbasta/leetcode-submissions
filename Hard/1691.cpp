class Solution {
public:
    int maxHeight(vector<vector<int>>& cub) {
        int M = 100;
        int DP[M + 5][M + 5][M + 5], cnt[M + 5][M + 5][M + 5];
        memset(cnt, 0, sizeof(cnt));
        memset(DP, 0, sizeof(DP));

        for (auto c : cub) {
            sort(c.begin(), c.end());
            int x = c[0], y = c[1], z = c[2];
            if (c[0] == c[2]) {
                cnt[x][x][x]++;
            } else if (c[0] == c[1]) {
                cnt[x][x][z]++, cnt[x][z][x]++, cnt[z][x][x]++;
            } else if (c[1] == c[2]) {
                cnt[x][z][z]++, cnt[z][x][z]++, cnt[z][z][x]++;
            } else {
                cnt[x][y][z]++, cnt[x][z][y]++;
                cnt[y][x][z]++, cnt[y][z][x]++;
                cnt[z][x][y]++, cnt[z][y][x]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= M; j++) {
                for (int k = 1; k <= M; k++) {
                    int mx = cnt[i][j][k] * k + DP[i][j][k];
                    ans = max(ans, mx);
                    DP[i][j][k + 1] = max(DP[i][j][k + 1], mx);
                    DP[i][j + 1][k] = max(DP[i][j + 1][k], mx);
                    DP[i + 1][j][k] = max(DP[i + 1][j][k], mx);
                }
            }
        }
        return ans;
    }
};