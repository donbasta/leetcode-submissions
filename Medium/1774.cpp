class Solution {
public:
    int closestCost(vector<int>& bc, vector<int>& tc, int target) {
        const int M = 2e4;
        int n = tc.size();
        bool dp[M + 5][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        dp[tc[0]][0] = true;
        dp[2 * tc[0]][0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= M; j++) {
                dp[j][i] = (dp[j][i] || dp[j][i - 1]);
                if (j >= tc[i]) dp[j][i] = (dp[j][i] || dp[j - tc[i]][i - 1]);
                if (j >= 2 * tc[i]) dp[j][i] = (dp[j][i] || dp[j - tc[i] * 2][i - 1]);
            }
        }
        int mn = INT_MAX;
        int ans = -1;
        for (auto e : bc) {
            for (int i = 0; i <= M; i++) {
                if (!dp[i][n - 1]) continue;
                if (abs(target - (e + i)) < mn) {
                    ans = e + i;
                    mn = abs(target - ans);
                } else if (abs(target - (e + i)) == mn && (e + i) < ans) {
                    ans = e + i;
                }
            }
        }
        return ans;
    }
};