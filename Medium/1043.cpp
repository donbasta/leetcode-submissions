class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // dp[i][j] = dp[p][j - 1] + (i - p) * max(arr[p + 1], ..., ar[i])

        int n = arr.size();
        vector<vector<int>> mx(n, vector<int>(n)), dp(n, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++) {
            mx[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                mx[i][j] = max(mx[i][j - 1], arr[j]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i < k) {
                dp[i][1] = (i + 1) * mx[0][i];
            }
            for (int j = 2; j <= n; j++) {
                for (int kk = max(0, i - k); kk <= i - 1; kk++) {
                    if (dp[kk][j - 1] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[kk][j - 1] + (i - kk) * mx[kk + 1][i]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[n - 1][i]);
        }
        return ans;
    }
};