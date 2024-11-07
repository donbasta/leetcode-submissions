class Solution {
public:
    int longestString(int x, int y, int z) {
        // dp[x][y][z][0] = (dp[x - 1][y][z][1]) or (dp[x - 1][y][z][2])
        // dp[x][y][z][1] = (dp[x][y - 1][z][0])
        // dp[x][y][z][2] = (dp[x][y][z - 1][1]) or (dp[x][y][z - 1][2])

        bool dp[x + 1][y + 1][z + 1][3];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 3; i++) dp[0][0][0][i] = true;
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                for (int k = 0; k <= z; k++) {
                    if (i > 0) dp[i][j][k][0] = (dp[i][j][k][0] || dp[i - 1][j][k][1] || dp[i - 1][j][k][2]);
                    if (j > 0) dp[i][j][k][1] = (dp[i][j][k][1] || dp[i][j - 1][k][0]);
                    if (k > 0) dp[i][j][k][2] = (dp[i][j][k][2] || dp[i][j][k - 1][1] || dp[i][j][k - 1][2]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                for (int k = 0; k <= z; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (dp[i][j][k][l]) {
                            ans = max(ans, 2 * (i + j + k));
                        }
                    }
                }
            }
        }
        return ans;
    }
};