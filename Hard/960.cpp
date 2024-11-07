class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        const int INF = 2e9;
        int dp[m];
        dp[0] = 0;

        bool ok[m][m];
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                ok[i][j] = true;
                for (int k = 0; k < n; k++) {
                    ok[i][j] = ok[i][j] && (strs[k][i] <= strs[k][j]);
                }
            }
        }

        for (int i = 1; i < m; i++) {
            dp[i] = i;
            for (int j = 0; j < i; j++) {
                if (ok[j][i]) {
                    dp[i] = min(dp[i], i - j - 1 + dp[j]);
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < m; i++) {
            ans = min(ans, dp[i] + m - 1 - i);
        }
        return ans;
    }
};